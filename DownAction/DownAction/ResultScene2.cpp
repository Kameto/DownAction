#include "ResultScene2.h"

ResultScene2::ResultScene2() 
	: BaseScene()
{
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	rand = MyRand::GetRand() % (int)ItemName::mAll;
#ifdef _DEBUG
	if (ItemMgr::CheckItem() == false)
	{
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
	}
#else
#endif
	sceneFlag = false;
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
}

void ResultScene2::Update() 
{
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		sceneFlag = true;
	}

	if (rand == 0)
	{
		if (counter[0] < 150)
		{
			counter[0]++;
		}
		else
		{
			if (counter[1] < 5)
			{
				counter[1]++;
			}
			else
			{
				counter[1] = 0;
				counter[0] = 0;
			}
		}
	}

	if (counter[2] < 490)
	{
		counter[2] += 4;
	}

	if (sceneFlag == true)
	{
		BaseScene::FadeOut(SceneName::eGame);
	}
}

void ResultScene2::Draw() 
{
	DrawExtendFormatString(600, 128, 1.5, 1.5, 0xFFFFFF, "%d / %d", BaseScene::nowStage + 1, BaseScene::stageNum);

	// ƒvƒŒƒCƒ„[
	if (counter[2] < 490)
	{
		DrawRotaGraph(920, counter[2] - 16, 1.0, 0.0, Graphics::GetPlayerGraph(CS::mDown), true);
	}
	else
	{
		DrawRotaGraph(920, counter[2] - 16, 1.0, 0.0, Graphics::GetPlayerGraph(CS::mNomal), true);
	}

	if (sceneFlag == true)
	{
		SetDrawBright(255 - BaseScene::counter, 255 - BaseScene::counter, 255 - BaseScene::counter);
	}
}