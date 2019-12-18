#include"GameScene.h"

GameScene::GameScene()
	: BaseScene()
{
	// ���[�J���|�C���^�[������
	p1	 = new Player();
	cmr	 = new Camera();
	font = new Font("MS �S�V�b�N", DX_FONTTYPE_ANTIALIASING_EDGE);
	tw	 = new TimeWatch();
	
	this->StageCreate(0);
	
	DataFile::LoadText();

	// ���[�J���ϐ�������
	goalPoint	 = (STAGE_HIEGHT * 32);
	counter[0]	 = 0;
	counter[1]	 = 0;
	counter[2]	 = 0;
	counter[3]	 = 0;
	goalFlag	 = false;
	overFlag	 = false;
	explanFlag	 = false;
	tEndFlag	 = false;
	getFlag		 = false;
	brightFlag	 = true;
	stickX		 = TRANS_SX;
	stickY		 = TRANS_SY;
	radian		 = 0.0;
	range		 = 0;
	SetDrawBright(255, 255, 255);
}

GameScene::~GameScene()
{
	// �X�R�A�E�^�C���L��
	if (goalFlag == true || overFlag == true)
	{
		DataFile::time.push_back(tw->GetTime());
		DataFile::score.push_back(Score::score);
	}
	Score::ScoreReset();
	
	// �|�C���^�[������
	DEL_OBJ(tw);
	DEL_OBJ(p1);
	DEL_OBJ(cmr);
	DEL_OBJ(font);
	StageRelease(true);

	// ���[�J���ϐ��ď�����
	goalPoint	 = 0;
	counter[0]	 = 0;
	counter[1]	 = 0;
	counter[2]	 = 0;
	counter[3]	 = 0;
	goalFlag	 = false;
	overFlag	 = false;
	explanFlag	 = false;
	tEndFlag	 = false;
	getFlag		 = false;
	brightFlag	 = true;
}

void GameScene::StageCreate(const int _stage)
{
	if (_stage != 0)
	{
		std::string path = "datafile/blocks("+std::to_string(_stage)+").csv";
		if (DataFile::Load(path) == 0)
		{
			for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
			{
				block.push_back(new Block(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
			}
			DataFile::Clear();
		}

		path = "datafile/items(" + std::to_string(_stage) + ").csv";
		if (DataFile::Load(path) == 0)
		{
			for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
			{
				item.push_back(new Item(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
			}
			DataFile::Clear();
		}

		path = "datafile/enemy(" + std::to_string(_stage) + ").csv";
		if (DataFile::Load(path) == 0)
		{
			for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
			{
				enemy.push_back(new Enemy(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
			}
			DataFile::Clear();
		}
	}
	else
	{
		if (DataFile::Load("datafile/blocks.csv") == 0)
		{
			for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
			{
				block.push_back(new Block(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
			}
			DataFile::Clear();
		}

		if (DataFile::Load("datafile/item.csv") == 0)
		{
			for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
			{
				item.push_back(new Item(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
			}
			DataFile::Clear();
		}

		if (DataFile::Load("datafile/enemy.csv") == 0)
		{
			for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
			{
				enemy.push_back(new Enemy(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
			}
			DataFile::Clear();
		}
	}
}

void GameScene::StageRelease(const bool flag)
{
	if (!enemy.empty())
	{
		for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
		{
			DEL_OBJ(enemy[i]);
		}
	}

	if (!block.empty())
	{
		for (int i = 0, n = (unsigned)block.size(); i < n; i++)
		{
			DEL_OBJ(block[i]);
		}
	}

	if (!item.empty())
	{
		for (int i = 0, n = (unsigned)item.size(); i < n; i++)
		{
			DEL_OBJ(item[i]);
		}
	}
	if (flag == true)
	{
		enemy.erase(enemy.begin(), enemy.end());
		enemy.shrink_to_fit();

		block.erase(block.begin(), block.end());
		block.shrink_to_fit();

		item.erase(item.begin(), item.end());
		item.shrink_to_fit();
	}
}

void GameScene::GimmickUpdate()
{
	/*///////////////////////////////////////////////*/
	/*				�X�e�B�b�N����					 */
	/*///////////////////////////////////////////////*/
	// ���W�A���p�̑���
	if (Keyboard::GetKey(KEY_INPUT_RIGHT) > 0)
	{
		radian += (6.0 * PI) / 360.0;
		if (radian >= (6.0 * PI))
		{
			radian -= 6.0 * PI;
		}
	}
	else if (Keyboard::GetKey(KEY_INPUT_LEFT) > 0)
	{
		radian -= (6.0 * PI) / 360.0;
		if (radian >= (6.0 * PI))
		{
			radian += 6.0 * PI;
		}
	}

	// ���S����̋����ʂ̑���
	if (Keyboard::GetKey(KEY_INPUT_UP) > 0)
	{
		if (range < 20)
		{
			range += 4;
		}
	}
	else
	{
		if (range > 0)
		{
			range -= 4;
		}
	}
	
	stickX = TRANS_SX + (cos(radian) * range);
	stickY = TRANS_SY + (sin(radian) * range);
	/*//////////////////////////////////////////////*/


	/*//////////////////////////////////////////////*/
	/*				�v���C���[�ϐg����				*/
	/*//////////////////////////////////////////////*/
	// �ϐg�O�L�[���͏���
	if (p1->fuwaFlag == false && p1->kataFlag == false)
	{
		if (Keyboard::GetKey(KEY_INPUT_SPACE) == 1)
		{
			if (range > 12 && p1->enegy * ENEGY_UP == ENEGY_MAX)
			{
				if (stickX > TRANS_SX)
				{
					p1->fuwaFlag = true;
				}
				else
				{
					p1->kataFlag = true;
				}
			}
		}
	}
	/*//////////////////////////////////////////////*/

	// �A�C�e���擾���G�t�F�N�g����
	if (getFlag == true)
	{
		counter[0]++;
		if (counter[0] == 255)
		{
			counter[0] = 0;
			getFlag = false;
		}
	}
}

void GameScene::PlayerUpdate()
{
	p1->Update();
	cmr->Update(p1->mpPoint->ccx, p1->mpPoint->ccy);
	this->GimmickUpdate();

	// �̗͂��Ȃ��Ȃ�����
	if (p1->life == 0)
	{
		overFlag = true;
	}

	// �S�[�����C���ɂ�����
	if (p1->mpPoint->cy + Camera::my >= goalPoint)
	{
		goalFlag = true;
	}
}

void GameScene::EnemyUpdate()
{
	for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
	{
		enemy[i]->Update();

		if (abs(enemy[i]->mpPoint->cy - p1->mpPoint->ccy) <= 250)
		{
			enemy[i]->mpInfo->activFlag = true;
			if (enemy[i]->mpPoint->cx < p1->mpPoint->ccx)
			{
				enemy[i]->mpInfo->dirFlag = true;
			}
			else
			{
				enemy[i]->mpInfo->dirFlag = false;
			}
		}
		else
		{
			enemy[i]->mpInfo->activFlag = false;
			if ((p1->mpPoint->ccy - enemy[i]->mpPoint->cy) >= 600)
			{
				enemy.erase(enemy.begin() + i);
				break;
			}
		}

		if (p1->HitObject(enemy[i]) && p1->damegeFlag == false)
		{
			p1->life--;
			p1->damegeFlag = true;
			break;
		}
	}
}

void GameScene::BlockUpdate()
{
	// �u���b�N�̏���
	for (int i = 0, n = (unsigned)block.size(); i < n; i++)
	{
		block[i]->Update();
		if (p1->HitObject(block[i]))
		{
			p1->mpInfo->downFlag = false;
			p1->mpInfo->hitObjFlag = true;
			block[i]->mpInfo->hitObjFlag = true;
			if (p1->kataFlag == true && p1->actionFlag == false)
			{
				if (p1->enegy > 0)
				{
					p1->enegy -= 4;
				}
				else
				{
					p1->enegy = 0;
				}
				block.erase(block.begin() + i);
			}
			break;
		}
		else
		{
			p1->mpInfo->downFlag = true;
			p1->mpInfo->hitObjFlag = false;
			block[i]->mpInfo->hitObjFlag = false;
		}
	}
}

void GameScene::ItemUpdate()
{
	// �A�C�e���̏���
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		item[i]->Update();
		if (p1->HitObject(item[i]))
		{
			item[i]->mpInfo->activFlag = false;
			item.erase(item.begin() + i);
			Score::score += 100;
			if (getFlag == false)
			{
				getFlag = true;
			}
			else
			{
				counter[0] = 0;
			}
			if (p1->enegy < (ENEGY_MAX / ENEGY_UP) && (p1->kataFlag == false && p1->fuwaFlag == false))
			{
				p1->enegy++;
			}
			break;
		}
		else {}
	}
}

void GameScene::Update()
{
	// �S�[�����Ă��Ȃ��A�v���C���[������ł��Ȃ��A����N������Ȃ�
	if (goalFlag == false && overFlag == false && explanFlag == false)
	{
		// �I�u�W�F�N�g���Ƃ̏���
		tw->Update();
		this->PlayerUpdate();
		this->EnemyUpdate();
		this->BlockUpdate();
		this->ItemUpdate();

		if (BaseScene::firstFlag == true)
		{
			explanFlag = true;
		}
	}
	else
	{
		// ����N�������ǂ���
		if (explanFlag == false)
		{
			//	�N���A���̏���
			tw->tFlag = false;

			// ���ʒ���
			if (counter[3] < 256 && brightFlag == true)
			{
				counter[3]++;
			}
			else
			{
				brightFlag = false;
			}
			
			if (counter[3] > 30 && brightFlag == false)
			{
				counter[3]--;
			}
			else
			{
				brightFlag = true;
			}


			if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
			{
				BaseScene::nowScene = SceneName::eResult;
			}
		}
		else
		{
			//	���������ǂݐi�߂�
			if (Keyboard::GetKey(KEY_INPUT_SPACE) == 1)
			{
				if (tEndFlag == true)
				{
					if (counter[1] < 3)
					{
						counter[1]++;
					}
					else
					{
						explanFlag = false;
						BaseScene::firstFlag = false;
						counter[1] = 0;
					}
					tEndFlag = false;
				}
			}
		}
	}

#ifdef _DEBUG
	// �V�[���ؑ�
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		BaseScene::nowScene = SceneName::eResult;
	}

	//���W������
	if (Keyboard::GetKey(KEY_INPUT_R) == 1)
	{
		p1->mpPoint->cx = 600;
		p1->mpPoint->cy = 0;
	}
#endif
}

void GameScene::StageDraw()
{
	// �摜�Ȃǂ̕`��
	DrawGraph(0, 0, Graph::GetMainGraph(MG::mBack), true);
	DrawBox(0, 9460, 1080, 9460 + 16, 0xFF0000, true);

	// ��ʘg
	//DrawBox(0, 0, WALL_WIDTH, 1080, 0xFF0077, true);
	DrawGraph(0, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	//DrawBox(1920 - WALL_WIDTH, 0, 1920, 1080, 0xFF0077, true);
	DrawGraph(1920 - WALL_WIDTH, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawBox(0, goalPoint - Camera::my, 1920, goalPoint + 16 - Camera::my, 0xFFFFFF, true);
	

	// ���C�t&�G�l���M�[�Q�[�W
	DrawBox(1800 - 64, 460 - 256, 1800 + 64, 460 + 256, 0x105050, true);
	DrawBox(1800 - 64, (460 + 256) - (p1->enegy * ENEGY_UP), 1800, (460 + 256), 0x0000FF, true);
	DrawBox(1800, (460 + 256) - (p1->life * 128), 1800 + 64, (460 + 256), 0x0FFFFF0, true);
	DrawRotaGraph(1800, 460, 0.5, 0.0, Graph::GetMainGraph(MG::mGauge), true, false);

	// �ϐg�g
	DrawRotaGraph(TRANS_SX, TRANS_SY, 1.0, 0.0, Graph::GetMainGraph(MG::mChange), true, false);
	DrawRotaGraph(stickX, stickY, 1.0, 0.0, Graph::GetMainGraph(MG::mStick), true, false);

	// ���ԕ\��
	if (tw->mSecond >= 10)
	{
		DrawExtendFormatString(WIND_WIDTH / 2 - 128, 32, 4.0, 2.0, 0xFFFFFF, "%d.%.0f", tw->second, tw->mSecond);
	}
	else
	{
		DrawExtendFormatString(WIND_WIDTH / 2 - 128, 32, 4.0, 2.0, 0xFFFFFF, "%d.0%.0f", tw->second, tw->mSecond);
	}

	// �������\��
	if (explanFlag == true && counter[1] < 4)
	{
		DrawRotaGraph(WIND_WIDTH / 2, (WIND_HEIGHT / 6) * 5, 0.75, 0.0, Graphics::GetMainGraph(MG::mComent), true);
		DrawExtendFormatStringToHandle(304, 848, 1.0, 1.0, 0xFFFFFF, font->GetHandle(), DataFile::text.at(counter[1]).c_str());
		tEndFlag = true;
	}

	// �ϐg�w��
	if (p1->enegy == (ENEGY_MAX / 32))
	{
		DrawExtendStringToHandle(WIND_WIDTH / 2 - 384, 384, 1.0,1.0,"�X�e�B�b�N���񂵂�\nSPACE or L2�ŕϐg���悤�I", 0xFFFFFF, font->GetHandle());
	}
}

void GameScene::Draw() 
{
	// �w�i�⏬���̕`��
	this->StageDraw();
	
	// �I�u�W�F�N�g���Ƃ̕`��
	if (explanFlag == false)
	{
		p1->Draw();
		for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
		{
			enemy[i]->Draw();
		}
		for (int i = 0, n = (unsigned)item.size(); i < n; i++)
		{
			item[i]->Draw();
		}
		for (int i = 0, n = (unsigned)block.size(); i < n; i++)
		{
			block[i]->Draw();
			if (p1->blockFlag == true)
			{
				block[i]->transFlag = true;
			}
			else
			{
				block[i]->transFlag = false;
			}
		}
	}

	// �X�R�A�\��
	if (getFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255 - counter[0]);
		DrawExtendFormatString(WIND_WIDTH / 2 - 128, WIND_HEIGHT / 2, 8.0, 4.0, 0xFFFFFF, "%d", Score::score);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}


	// �S�[���������ʂ𔒂�����
	if (goalFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 50);
		DrawBox(0, 0, 1920, 1080, 0xFF0000, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		DrawRotaGraph(WIND_WIDTH / 2, WIND_HEIGHT / 2, 1.0, 0.0, Graphics::GetMainGraph(MG::mGameClear), true, false);
	}

	if (overFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		DrawBox(0, 0, 1920, 1080, 0x0000FF, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		DrawRotaGraph(WIND_WIDTH / 2, WIND_HEIGHT / 2, 1.0, 0.0, Graphics::GetMainGraph(MG::mGameOver), true, false);
	}

	if (overFlag == true || goalFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, counter[3]);
		DrawExtendString(650, 1020, 2.0, 2.0, "Enter�L�[�Ń��U���g�Ɉړ�", 0xFFFFFF);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}

#ifdef _DEBUG
	DrawFormatString(0, 0, 0xFFFFFF, "NowScene is Game\npless Enter to next");

	// �J�����̏��(�ړ���)
	DrawFormatString(0, 32, 0xFFFFFF, "�J����MX : %.1f\n�J����MY : %.1f", cmr->mx, cmr->my);
	
	// �X�R�A
	DrawFormatString(0, 64, 0xFFFFFF, "�X�R�A : %d", Score::score);
	
	// �v���C���[�̏��
	DrawFormatString(0, 96, 0xFFFFFF, "PX : %.1f\nPY : %.1f\nP�X�s�[�h : %.1f\nP�d�� : %.1f", p1->mpPoint->cx, p1->mpPoint->cy, p1->mpPoint->speed, p1->mpPoint->gravty);

	// �v���C���[�ϐg�t���O
	DrawString(0, 192, p1->fuwaFlag ? "fuwaFlag : true" : "fuwaFlag : false", 0xFFFFFF);
	DrawString(0, 224, p1->kataFlag ? "kataFlag : true" : "kataFlag : false", 0xFFFFFF);

	// �G���\��
	DrawFormatString(0, 256, 0xFFFFFFF, "enemy:%d", (unsigned)enemy.size());

	// �A�C�e���t���O
	DrawString(0, 320, ItemMgr::possMaxFlag ? "ItemMaxFlag : true" : "ItemMaxFlag : false", 0xFFFFFF);

	// �u���b�N�̏��
	/*for (int i = 0, n = (unsigned)block.size(); i < n; i++)
	{
		DrawFormatString(300 , i * 32, 0xFFFFFF, "block[ %d ]->HitFlag", i);
		DrawFormatString(480 , i * 32, 0xFFFFFF, block[i]->mpInfo->hitObjFlag ? "true" : "false");
		if (block[i]->mpInfo->hitObjFlag == true)
		{
			DrawFormatString(200, 0, 0xFFFFFF, "Hit Now!!");
		}
	}*/
	
#endif
}