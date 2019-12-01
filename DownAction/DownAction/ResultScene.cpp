#include"ResultScene.h"

ResultScene::ResultScene()
	: BaseScene()
{
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	rand = MyRand::GetRand() % 3;
	sceneFlag = false;
}

ResultScene::~ResultScene()
{
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	rand = 0;
	sceneFlag = false;
}

void ResultScene::Update() 
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
		BaseScene::FadeOut(SceneName::eTitle);
	}
}

void ResultScene::Draw() 
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xFFFFFF, "NowScene is Result\npless Enter to next");
#endif

	// ステージアイテム
	DrawRotaGraph(870, 510, 1.0, 0.0, Graphics::GetMainGraph(MG::mAlter), true);
	if ((counter[2] < 470) == false)
	{
		DrawRotaGraph(860, 316, 1.0, 0.0, Graphics::GetMainGraph(MG::mComment2), true);
	}
	if (rand == 0)
	{
		DrawRotaGraph(845, 460, 1.5, 0.0, Graphics::GetCrystalGraph(counter[1]), true);
		DrawExtendFormatString(480, 260, 2.0, 2.0, 0x000000, "大きい水晶玉だ!\n持ち帰れなさそうだ。このまま置いておこう。");
	}
	else if (rand == 1)
	{
		DrawRotaGraph(845, 460, 1.5, 0.0, Graphics::GetMainGraph(MG::mBox), true);
		DrawExtendFormatString(480, 260, 2.0, 2.0, 0x000000, "宝箱があった！\n帰って開けてみよう!");
	}
	else
	{
		DrawExtendFormatString(480, 260, 2.0, 2.0, 0x000000, "何もないようだ。。。\n別の場所に行ってみよう。");
	}

	// プレイヤー
	if (counter[2] < 490)
	{
		DrawRotaGraph(920, counter[2] - 16, 1.0, 0.0, Graphics::GetPlayerGraph(CS::mDown), true);
	}
	else
	{
		DrawRotaGraph(920, counter[2] - 16, 1.0, 0.0, Graphics::GetPlayerGraph(CS::mNomal), true);
	}

	// 獲得スコア
	DrawRotaGraph(WIND_WIDTH / 2, 820, 2.0, PI / 2, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawGraph(0, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawGraph(1920 - WALL_WIDTH, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawBox(580, 580, 1200, 900, 0x000000, true);
	DrawExtendFormatString(600, 684, 2.0, 2.0, 0xFFFFFF, "獲　得　ス　コ　ア　＆　タ　イ　ム");
	if (!DataFile::time.empty())
	{
		DrawExtendFormatString(600, 748, 2.0, 2.0, 0xFFFFFF, "　　　　タ　イ　ム　：　%s", DataFile::time.at(DataFile::time.size() - 1).c_str());
	}
	if (!DataFile::score.empty())
	{
		DrawExtendFormatString(600, 812, 2.0, 2.0, 0xFFFFFF, "獲　得　ス　コ　ア　：　%d", DataFile::score.at(DataFile::score.size() - 1));
	}

	if (sceneFlag == true)
	{
		SetDrawBright(255 - BaseScene::counter, 255 - BaseScene::counter, 255 - BaseScene::counter);
	}

	DrawExtendString(650, 1020, 2.0, 2.0, "Enterキーでタイトルに移動 => => =>", 0xFFFFFF);
}