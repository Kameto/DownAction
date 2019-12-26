#include"TitleScene.h"

TitleScene::TitleScene()
	: BaseScene()
{
	sele = MG::mStart;
	sceneFlag = false;
	startFlag = true;
	SetDrawBright(0, 0, 0);
}

TitleScene::~TitleScene()
{
	sele = MG::mStart;
	sceneFlag = false;
}

void TitleScene::Update()
{
	if (sceneFlag == false && endFlag == false && startFlag == false)
	{
		// 遷移先決定
		if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
		{
			if (sele == MG::mStart)
			{
				sceneFlag = true;
			}
			else
			{
				endFlag = true;
			}
		}

		// 遷移先切替
		if (Keyboard::GetKey(KEY_INPUT_UP) == 1)
		{
			sele = MG::mStart;
		}
		else if (Keyboard::GetKey(KEY_INPUT_DOWN) == 1)
		{
			sele = MG::mEnd;
		}
		
		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_S) > 0) || 
			(JoyPad::Button_Get(PLAY_NUM_1 ,XINPUT_BUTTON_DPAD_LEFT) > 20 && JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_RIGHT_SHOULDER) > 20))
		{
			// スコアhtmlの表示
			//system("start firefox.exe file://D:/GitFiles/DownAction/DownAction/DownAction/datafile/scorefile/scoreData.html");
		}

		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_X) > 0) ||
			(JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_LEFT) > 20 && JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_LEFT_SHOULDER) > 20))
		{
			// 音楽プレーヤー再生
			//system("start StageCreater.exe");
		}

		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_Z) > 0) ||
			(JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_LEFT) > 20 && JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_BACK) > 20))
		{
			BaseScene::nowScene = SceneName::eIC_Scene;
		}
	}
	else if (sceneFlag == true)
	{
		BaseScene::FadeOut(SceneName::eGame);
	}
	else if (startFlag == true)
	{
		BaseScene::FadeIn();
		if (BaseScene::counter == 255)
		{
			startFlag = false;
			BaseScene::counter = 0;
		}
	}
}

void TitleScene::Draw() 
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xFFFFFF, "NowScene is Title\npless Enter to next");
#endif
	DrawGraph(0, 0, Graph::GetMainGraph(MG::mBack), true);
	DrawRotaGraph(900, 300, 1.5, 0.0, Graph::GetMainGraph(MG::mTitle), true);
	DrawGraph(700, 600, Graph::GetMainGraph(sele), true);

	DrawGraph(0, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawGraph(1920 - WALL_WIDTH, 0, Graphics::GetMainGraph(MG::mStoneWall), false);

	DrawExtendString(650, 1020, 2.0, 2.0, "矢印キー↑↓で選択。Enterキーで決定。", 0xFFFFFF);

#ifdef _DEBUG
	DrawFormatString(0, 0, 0xFFFFFF, "%d", BaseScene::counter );
	DrawFormatString(0, 32, 0xFFFFFF, sceneFlag ? "sceneFlag : true" : "sceneFlag : false");
	DrawFormatString(0, 63, 0xFFFFFF, startFlag ? "startFlag : true" : "startFlag : false");
#endif // _DEBUG

	if (sceneFlag == true)
	{
		SetDrawBright(255 - BaseScene::counter, 255 - BaseScene::counter, 255 - BaseScene::counter);
	}
	else if (startFlag == true)
	{
		SetDrawBright(BaseScene::counter, BaseScene::counter, BaseScene::counter);
	}
}