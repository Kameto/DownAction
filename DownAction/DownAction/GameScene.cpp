/*
学籍番号：j17086
名前：亀田朋来
*/

#include"GameScene.h"

GameScene::GameScene()
	: BaseScene()
{
	// ローカルポインター初期化
	p1	 = new Player();
	cmr	 = new Camera();
	font = new Font("MS ゴシック", DX_FONTTYPE_ANTIALIASING_EDGE);
	
	std::string path[3];
	if (BaseScene::nowStage > 0)
	{
		path[0] = "datafile/block/blocks(" + std::to_string(BaseScene::nowStage) + ").csv";
		path[1] = "datafile/item/item(" + std::to_string(BaseScene::nowStage) + ").csv";
		path[2] = "datafile/enemy/enemy(" + std::to_string(BaseScene::nowStage) + ").csv";
	}
	else
	{
		path[0] = "datafile/block/blocks.csv";
		path[1] = "datafile/item/item.csv";
		path[2] = "datafile/enemy/enemy.csv";
	}
	StageCreate(path);
	
	if (BaseScene::firstFlag)
	{
		DataFile::LoadText();
	}

	TimeWatch::ResetTimeWatch();

	// ローカル変数初期化
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
	TimeWatch::AddTime();
	Score::AddScore();
	Score::ScoreReset();
	
	// ポインター初期化
	DEL_OBJ(p1);
	DEL_OBJ(cmr);
	DEL_OBJ(font);
	StageRelease();

	// ローカル変数再初期化
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

void GameScene::StageCreate(const std::string path[])
{
	if (DataFile::Load(path[0]) == 0)
	{
		for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
		{
			block.push_back(new Block(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
		}
		DataFile::Clear();
	}
	if (DataFile::Load(path[1]) == 0)
	{
		for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
		{
			item.push_back(new Item(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
		}
		DataFile::Clear();
	}
	if (DataFile::Load(path[2]) == 0)
	{
		for (int i = 0, n = (unsigned)DataFile::objP.size(); i < n; i++)
		{
			enemy.push_back(new Enemy(DataFile::objP.at(i).x, DataFile::objP.at(i).y));
		}
		DataFile::Clear();
	}
}

void GameScene::StageRelease()
{
	if (!block.empty())
	{
		for (int i = 0, n = (unsigned)block.size(); i < n; i++)
		{
			DEL_OBJ(block[i]);
		}
		block.erase(block.begin(), block.end());
	}
	block.shrink_to_fit();
	if (!item.empty())
	{
		for (int i = 0, n = (unsigned)item.size(); i < n; i++)
		{
			DEL_OBJ(item[i]);
		}
		item.erase(item.begin(), item.end());
	}
	item.shrink_to_fit();
	if (!enemy.empty())
	{
		for (int i = 0, n = (unsigned)enemy.size(); i < n; i++)
		{
			DEL_OBJ(enemy[i]);
		}
		enemy.erase(enemy.begin(), enemy.end());
	}
	enemy.shrink_to_fit();
}

void GameScene::GimmickUpdate()
{
	/*///////////////////////////////////////////////*/
	/*				スティック処理					 */
	/*///////////////////////////////////////////////*/
	// ラジアン角の増減
	if (Keyboard::GetKey(KEY_INPUT_RIGHT) > 0)
	{
		radian += (6.0 * PI) / 360.0;
		if (radian >= (6.0 * PI)) { radian -= 6.0 * PI; }
	}
	else if (Keyboard::GetKey(KEY_INPUT_LEFT) > 0)
	{
		radian -= (6.0 * PI) / 360.0;
		if (radian >= (6.0 * PI)) { radian += 6.0 * PI; }
	}

	// 中心からの距離量の増減
	if (Keyboard::GetKey(KEY_INPUT_UP) > 0
		|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_A) > 0)
	{
		if (range < 20) { range += 4; }
	}
	else
	{
		if (range > 0) { range -= 2; }
	}

	// Xboxコントローラー専用機能(左右どちらかに移動する)
	if (JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_A) == 1)
	{
		if (radian == (0.0 * PI) / 360) { radian = (360.0 * PI) / 360; }
		else { radian = (00.0 * PI) / 360; }
	}
	
	stickX = TRANS_SX + (cos(radian) * range);
	stickY = TRANS_SY + (sin(radian) * range);
	/*//////////////////////////////////////////////*/


	/*//////////////////////////////////////////////*/
	/*				プレイヤー変身処理				*/
	/*//////////////////////////////////////////////*/
	// 変身前キー入力処理
	if (p1->fuwaFlag == false && p1->kataFlag == false)
	{
		if (Keyboard::GetKey(KEY_INPUT_SPACE) == 1 
			|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_RIGHT_SHOULDER) == 1)
		{
			if (range > 12 && p1->enegy * ENEGY_UP == ENEGY_MAX)
			{
				if (stickX > TRANS_SX) { p1->fuwaFlag = true; }
				else { p1->kataFlag = true; }
			}
		}
	}
	/*//////////////////////////////////////////////*/

	// アイテム取得時エフェクト処理
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

	// 体力がなくなったらゲームオーバー
	if (p1->life == 0){ overFlag = true; }

	// ゴールラインについたらゲームクリア
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

		// プレイヤーが索敵範囲内に入ったら移動する
		if (abs(enemy[i]->mpPoint->cy - p1->mpPoint->ccy) <= 250)
		{
			enemy[i]->mpInfo->activFlag = true;

			// 移動方向をプレイヤーがいる方向に設定する
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
		}

		// プレイヤーがエネミーにあたったらダメージを受ける
		if (p1->HitObject(enemy[i]) && p1->damegeFlag == false)
		{
			p1->life--;
			p1->damegeFlag = true;
			break;
		}

		// 画面から見えなくなったら消滅させる
		if ((p1->mpPoint->ccy - enemy[i]->mpPoint->cy) >= 600)
		{
			enemy.erase(enemy.begin() + i);
			break;
		}
	}
}

void GameScene::BlockUpdate()
{
	// ブロックの処理
	for (int i = 0, n = (unsigned)block.size(); i < n; i++)
	{
		block[i]->Update();
		// ブロックに触れていたら
		if (p1->HitObject(block[i]))
		{
			p1->mpInfo->downFlag = false;
			p1->mpInfo->hitObjFlag = true;
			block[i]->mpInfo->hitObjFlag = true;

			// 石化状態でブロックに触れたら
			// ブロックを破壊して変身時間を減少する
			if (p1->kataFlag == true && p1->actionFlag == false)
			{
				if (p1->enegy > 0){ p1->enegy -= 4;	}
				else{ p1->enegy = 0; }
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

		// 画面から消えたら消滅させる
		if ((p1->mpPoint->ccy - block[i]->mpPoint->cy) >= 600)
		{
			block.erase(block.begin() + i);
			break;
		}
	}
}

void GameScene::ItemUpdate()
{
	// アイテムの処理
	for (int i = 0, n = (unsigned)item.size(); i < n; i++)
	{
		item[i]->Update();
		
		// アイテムに触れたらスコアと変身ゲージを
		// 増加させて、アイテムを消滅させる
		if (p1->HitObject(item[i]))
		{
			item[i]->mpInfo->activFlag = false;
			item.erase(item.begin() + i);
			Score::score += 100;
			if (getFlag == false){ getFlag = true; }
			else{ counter[0] = 0; }

			// 変身ゲージ増加処理
			if (p1->enegy < (ENEGY_MAX / ENEGY_UP)
				&& (p1->kataFlag == false && p1->fuwaFlag == false))
			{
				p1->enegy++;
			}
			break;
		}
		else {}

		// 画面から消えたら消滅させる
		if ((p1->mpPoint->ccy - item[i]->mpPoint->cy) >= 600)
		{
			item.erase(item.begin() + i);
			break;
		}
	}
}

void GameScene::Update()
{
	// ゴールしていない、プレイヤーが死んでいない、初回起動じゃない
	if (goalFlag == false && overFlag == false && explanFlag == false)
	{
		/**** オブジェクトごとの処理 ****/
		TimeWatch::Update();
		this->PlayerUpdate();
		this->EnemyUpdate();
		this->BlockUpdate();
		this->ItemUpdate();
		/********************************/

		// 初回起動時のみ説明を起動させる
		if (BaseScene::firstFlag) { explanFlag = true; }
	}
	else
	{
		// 初回起動化かどうか
		if (explanFlag == false)
		{
			//	クリア時の処理
			TimeWatch::StopTimeWatch();

			// 文字光量調整
			if (counter[3] < 256 && brightFlag == true){ counter[3]++; }
			else{ brightFlag = false; }
			if (counter[3] > 30 && brightFlag == false){counter[3]--;}
			else{ brightFlag = true; }

			// シーン切替
			if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1 
				|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_B) == 1)
			{
				// ゲームオーバーの場合
				if (overFlag)
				{
					BaseScene::nowScene = SceneName::eResult;
				}

				// ゲームクリアの場合
				if ((BaseScene::stageNum - 1) > BaseScene::nowStage)
				{
					BaseScene::nowScene = SceneName::eResult2;
				}
				else
				{
					BaseScene::nowScene = SceneName::eResult;
				}
			}
		}
		else
		{
			//	操作説明を読み進める
			if (Keyboard::GetKey(KEY_INPUT_SPACE) == 1
				|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_B) == 1)
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
	// シーン切替
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1 
		|| JoyPad::Button_Get(PLAY_NUM_1 ,XINPUT_BUTTON_START) == 1)
	{
		if ((BaseScene::stageNum - 1) > BaseScene::nowStage)
		{
			BaseScene::nowScene = SceneName::eResult2;
		}
		else
		{
			BaseScene::nowScene = SceneName::eResult;
		}
	}
#else
	// Release時のdebugコード
	if (BaseScene::modeFlag)
	{
		if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1
			|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_START) == 1)
		{
			if ((BaseScene::stageNum - 1) > BaseScene::nowStage)
			{
				BaseScene::nowScene = SceneName::eResult2;
			}
			else
			{
				BaseScene::nowScene = SceneName::eResult;
			}
		}
	}
#endif
}

void GameScene::StageDraw()
{
	// 画像などの描画
	DrawGraph(0, 0, Graph::GetMainGraph(MG::mBack), true);
	DrawBox(0, 9460, 1080, 9460 + 16, 0xFF0000, true);

	// 画面枠
	DrawGraph(0, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawGraph(1920 - WALL_WIDTH, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawBox(0, goalPoint - (int)Camera::my, 1920, goalPoint + 16 - (int)Camera::my, 0xFFFFFF, true);

	// ライフ&エネルギーゲージ
	DrawBox(1800 - 64, 460 - 256, 1800 + 64, 460 + 256, 0x105050, true);
	DrawBox(1800 - 64, (460 + 256) - (p1->enegy * ENEGY_UP), 1800, (460 + 256), 0x0000FF, true);
	DrawBox(1800, (460 + 256) - (p1->life * 128), 1800 + 64, (460 + 256), 0x0FFFFF0, true);
	DrawRotaGraph(1800, 460, 0.5, 0.0, Graph::GetMainGraph(MG::mGauge), true, false);

	// 変身枠
	DrawRotaGraph(TRANS_SX, TRANS_SY, 1.0, 0.0, Graph::GetMainGraph(MG::mChange), true, false);
		DrawRotaGraph((int)stickX, (int)stickY, 1.0, 0.0, Graph::GetMainGraph(MG::mStick), true, false);

	// 時間表示
	if (TimeWatch::mSecond >= 10)
	{
		DrawExtendFormatString(WIND_WIDTH / 2 - 128, 32, 4.0, 2.0, 0xFFFFFF, 
			"%d.%.0f", TimeWatch::second, TimeWatch::mSecond);
	}
	else
	{
		DrawExtendFormatString(WIND_WIDTH / 2 - 128, 32, 4.0, 2.0, 0xFFFFFF,
			"%d.0%.0f", TimeWatch::second, TimeWatch::mSecond);
	}

	// 現在のステージ数
	DrawExtendFormatString(WIND_WIDTH / 2 - 448, 32, 4.0, 2.0, 0xFFFFFF, 
		"%d / %d", BaseScene::nowStage + 1, BaseScene::stageNum);

	// 説明文表示
	int size = (unsigned)DataFile::text.size();
	if (explanFlag && counter[1] < size)
	{
		// コメントフレーム+コメント
		DrawRotaGraph(WIND_WIDTH / 2, (WIND_HEIGHT / 6) * 5, 0.75, 0.0, 
			Graphics::GetMainGraph(MG::mComent), true);
		DrawExtendFormatStringToHandle(304, 848, 1.0, 1.0, 0xFFFFFF,
			font->GetHandle(), DataFile::text.at(counter[1]).c_str());

		// 指示コメント
		DrawExtendFormatStringToHandle(800, 980, 1.0, 1.0, 0xFFFFFF,
			font->GetHandle(), "Spacキー または Bボタン で 次へ");
		
		// 体力・変身ゲージ
		DrawExtendFormatString(1701, 160, 1.5, 1.5, 0x000000, "変身バー : HPバー\n　　↓　　↓");
		DrawExtendFormatString(1700, 160, 1.5, 1.5, 0xFF0000, "変身バー : HPバー\n　　↓　　↓");

		// タイマー
		DrawExtendFormatString(841, 80, 1.5, 1.5, 0x000000, "  ↑\nタイマー");
		DrawExtendFormatString(840, 80, 1.5, 1.5, 0xFF0000, "  ↑\nタイマー");

		// ステージ
		DrawExtendFormatString(541, 80, 1.5, 1.5, 0x000000, "  ↑\nステージ");
		DrawExtendFormatString(540, 80, 1.5, 1.5, 0xFF0000, "  ↑\nステージ");

		// アイテム
		DrawExtendFormatString(46, 160, 1.5, 1.5, 0x000000, "アイテム\n　　↓");
		DrawExtendFormatString(45, 160, 1.5, 1.5, 0xFF0000, "アイテム\n　　↓");

		tEndFlag = true;
	}

	// 変身指示
	if (p1->enegy == (ENEGY_MAX / 32))
	{
		DrawExtendStringToHandle(WIND_WIDTH / 2 - 384, 384, 1.0,1.0,
			"スティックを回して\nSPACE or L2で変身しよう！", 0xFFFFFF, font->GetHandle());
	}
}

void GameScene::Draw() 
{
	// 背景や小物、コメントの描画
	this->StageDraw();
	
	// オブジェクトごとの描画
	if (!explanFlag)
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

	// スコア表示
	if (getFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255 - counter[0]);
		DrawExtendFormatString(WIND_WIDTH / 2 - 128, WIND_HEIGHT / 2, 
			8.0, 4.0, 0xFFFFFF, "%d", Score::score);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}

	// ゴールしたら画面を白くする
	if (goalFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 50);
		DrawBox(0, 0, 1920, 1080, 0xFF0000, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		DrawRotaGraph(WIND_WIDTH / 2, WIND_HEIGHT / 2, 1.0, 0.0, 
			Graphics::GetMainGraph(MG::mGameClear), true, false);
	}

	// ゲームオーバーになったら画面を薄緑にする
	if (overFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		DrawBox(0, 0, 1920, 1080, 0x0000FF, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		DrawRotaGraph(WIND_WIDTH / 2, WIND_HEIGHT / 2, 1.0, 0.0, 
			Graphics::GetMainGraph(MG::mGameOver), true, false);
	}

	// 指示表記
	if (overFlag == true || goalFlag == true)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, counter[3]);
		DrawExtendString(650, 1020, 2.0, 2.0, "Enterキーでリザルトに移動", 0xFFFFFF);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}

#ifdef _DEBUG
	// 現在シーン
	DrawFormatString(0, 0, 0xFFFFFF, "NowScene is Game\npless Enter to next");

	// カメラの状態(移動量)
	DrawFormatString(0, 32, 0xFFFFFF, "カメラMX : %.1f\nカメラMY : %.1f", cmr->mx, cmr->my);
	
	// スコア
	DrawFormatString(0, 64, 0xFFFFFF, "スコア : %d", Score::score);
	
	// プレイヤーの情報
	DrawFormatString(0, 96, 0xFFFFFF, "PX : %.1f\nPY : %.1f\nPスピード : %.1f\nP重力 : %.1f",
		p1->mpPoint->cx, p1->mpPoint->cy, p1->mpPoint->speed, p1->mpPoint->gravty);

	// プレイヤー変身フラグ
	DrawString(0, 192, p1->fuwaFlag ? "fuwaFlag : true" : "fuwaFlag : false", 0xFFFFFF);
	DrawString(0, 224, p1->kataFlag ? "kataFlag : true" : "kataFlag : false", 0xFFFFFF);
	DrawFormatString(0, 256, 0xFFFFFFF, "bCount : %d___wCount : %d", p1->bCount, p1->wCount);

	// 敵数表示
	DrawFormatString(0, 288, 0xFFFFFFF, "enemy:%d", (unsigned)enemy.size());

	// アイテムフラグ
	DrawString(0, 320, ItemMgr::possMaxFlag ? "ItemMaxFlag : true" : "ItemMaxFlag : false", 0xFFFFFF);
	DrawFormatString(0, 352, 0xFFFFFFF, "setItem[0] : %d\nsetItem[1] : %d\nsetItem[2] : %d",
		ItemMgr::setItem[0], ItemMgr::setItem[1], ItemMgr::setItem[2]);
#else
	// Release時のdebugコード(内容は上記と同じもの)
	if (BaseScene::modeFlag)
	{
		DrawFormatString(0, 0, 0xFFFFFF, "NowScene is Game\npless Enter to next");
		DrawFormatString(0, 32, 0xFFFFFF, "カメラMX : %.1f\nカメラMY : %.1f", cmr->mx, cmr->my);
		DrawFormatString(0, 64, 0xFFFFFF, "スコア : %d", Score::score);
		DrawFormatString(0, 96, 0xFFFFFF, "PX : %.1f\nPY : %.1f\nPスピード : %.1f\nP重力 : %.1f",
			p1->mpPoint->cx, p1->mpPoint->cy, p1->mpPoint->speed, p1->mpPoint->gravty);
		DrawString(0, 192, p1->fuwaFlag ? "fuwaFlag : true" : "fuwaFlag : false", 0xFFFFFF);
		DrawString(0, 224, p1->kataFlag ? "kataFlag : true" : "kataFlag : false", 0xFFFFFF);
		DrawFormatString(0, 256, 0xFFFFFFF, "bCount : %d___wCount : %d", p1->bCount, p1->wCount);
		DrawFormatString(0, 288, 0xFFFFFFF, "enemy:%d", (unsigned)enemy.size());
		DrawString(0, 320, ItemMgr::possMaxFlag ? "ItemMaxFlag : true" : "ItemMaxFlag : false", 0xFFFFFF);
		DrawFormatString(0, 352, 0xFFFFFFF, "setItem[0] : %d\nsetItem[1] : %d\nsetItem[2] : %d", 
			ItemMgr::setItem[0], ItemMgr::setItem[1], ItemMgr::setItem[2]);
	}
#endif
}