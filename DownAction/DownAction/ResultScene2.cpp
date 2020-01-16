/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#include "ResultScene2.h"

ResultScene2::ResultScene2() 
	: BaseScene()
{
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	rand = MyRand::GetRand() % (int)ItemName::mAll;
	checkFlag = ItemMgr::CheckItem();
	if (checkFlag == false)
	{
		// �A�C�e���������
		while (true)
		{
			if (ItemMgr::possItemFlag[rand] == false)
			{
				ItemMgr::possItemFlag[rand] = true;
				break;
			}
			else
			{
				if (rand == ((int)ItemName::mAll - 1))
				{
					rand = 0;
				}
				else
				{
					rand++;
				}
			}
		}

		// �A�C�e���Z�b�g����
		for (int i = 0, n = ItemMgr::possItem; i < n; i++)
		{
			if (ItemMgr::setItem[i] == -1)
			{
				ItemMgr::setItem[i] = rand;
				break;
			}
		}
	}
	sceneFlag = false;
	moveFlag = true;
}

ResultScene2::~ResultScene2()
{
	BaseScene::nowStage++;
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	rand = 0;
	sceneFlag = false;
	moveFlag = false;
}

void ResultScene2::Update() 
{
	// �L�����̈ړ��Ƃ�
	if (moveFlag)
	{
		counter[2] += 4;
		if (counter[2] == 480)
		{
			moveFlag = false;
		}

		if (counter[2] > 960)
		{
			sceneFlag = true;
		}
	}
	else
	{
		if (counter[3] < 200)
		{
			counter[3]++;
		}
		else
		{
			if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1 || JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_B) == 1)
			{
				moveFlag = true;
			}
		}
	}

	// �V�[���ؑ�
	if (sceneFlag == true)
	{
		BaseScene::FadeOut(SceneName::eGame);
	}
}

void ResultScene2::Draw() 
{
	DrawGraph(0, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawGraph(1920 - WALL_WIDTH, 0, Graphics::GetMainGraph(MG::mStoneWall), false);

#ifdef _DEBUG
	DrawExtendFormatString(1920 / 2, 128, 2.5, 2.5, 0xFFFFFF, "%d / %d", BaseScene::nowStage + 1, BaseScene::stageNum);
	DrawExtendFormatString(1920 / 2, 192, 2.5, 2.5, 0xFFFFFF, "counter[3] : %d",counter[3]);
#endif

	// �v���C���[
	DrawRotaGraph(WIND_WIDTH / 2, counter[2] - 16, 1.0, 0.0, Graphics::GetPlayerGraph(CS::mDown), true);

	// ��ʈÓ]����
	if (sceneFlag == true)
	{
		SetDrawBright(255 - BaseScene::counter, 255 - BaseScene::counter, 255 - BaseScene::counter);
	}

	// �A�C�e��
	if (moveFlag == false)
	{
		if (counter[3] < 200)
		{
			DrawRotaGraph(WIND_WIDTH / 2, WIND_HEIGHT / 2 - 288, 1.5, 0.0, Graphics::GetMojiGraph(Moji::mDoxuru), true, false);
			DrawRotaGraph(WIND_WIDTH / 2, WIND_HEIGHT / 2 + 224, 1.5, 0.0, Graphics::GetMainGraph(MG::mCandela + (counter[3] % (int)ItemName::mAll)), false, false);
			DrawBoxAA(WIND_WIDTH / 2 - 256, WIND_HEIGHT / 2 - 256 + 224, WIND_WIDTH / 2 + 256, WIND_HEIGHT / 2 + 256 + 224, 0xFFFFFF, false, 10.0f);
		}
		else
		{
			if (checkFlag)
			{
				DrawExtendFormatString(WIND_WIDTH / 2 - 448, WIND_HEIGHT / 2 - 256,5.5, 5.5, 0xFFFFFF, "Item Complated !!!");
			}
			else
			{
				DrawRotaGraph(WALL_WIDTH + 128, WIND_HEIGHT / 2, 1.5, 0.0, Graphics::GetMojiGraph(Moji::mDen), true, false);
				DrawRotaGraph(1920 - WALL_WIDTH - 128, WIND_HEIGHT / 2, 1.5, 0.0, Graphics::GetMojiGraph(Moji::mDen), true, false);
				DrawRotaGraph(WIND_WIDTH / 2, WIND_HEIGHT / 2 + 224, 1.5, 0.0, Graphics::GetMainGraph(MG::mCandela + rand), false, false);
				DrawBoxAA(WIND_WIDTH / 2 - 256, WIND_HEIGHT / 2 - 256 + 224, WIND_WIDTH / 2 + 256, WIND_HEIGHT / 2 + 256 + 224, 0xFFFFFF, false, 10.0f);
			}
			DrawExtendFormatString(WIND_WIDTH / 2 - 448, WIND_HEIGHT / 2 + 488, 2.5, 2.5, 0xFFFFFF, "Enter �L�[�@�� A�{�^���@=>�@���̃X�e�[�W");
		}
	}
}