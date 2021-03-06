/*
学籍番号：j17086
名前：亀田朋来
*/

#include"TitleScene.h"

TitleScene::TitleScene()
	: BaseScene()
{
	sele = MG::mStart;
	sceneFlag = false;
	startFlag = true;
	SetDrawBright(0, 0, 0);
	cmtCounter = 0;
	cmtFlag = false;
	modeCount = 0;
}

TitleScene::~TitleScene()
{
	sele = MG::mStart;
	sceneFlag = false;
	cmtCounter = 0;
	cmtFlag = false;
}

void TitleScene::Update()
{
	// シーン内キーコマンド処理 & フェード・画面切り替え処理
	if (sceneFlag == false && endFlag == false && startFlag == false)
	{
		// 遷移先決定
		if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1 
			|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_B) == 1)
		{
			if (sele == MG::mStart) { sceneFlag = true; }
			else { endFlag = true; }
		}

		// 遷移先切替
		if (Keyboard::GetKey(KEY_INPUT_UP) == 1 
			|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_UP) == 1)
		{
			sele = MG::mStart;
		}
		else if (Keyboard::GetKey(KEY_INPUT_DOWN) == 1 
			|| JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_DOWN) == 1)
		{
			sele = MG::mEnd;
		}
		
		// スコア参照
		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_S) > 0) || 
			(JoyPad::Button_Get(PLAY_NUM_1 ,XINPUT_BUTTON_DPAD_LEFT) > 20 
				&& JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_Y) > 20))
		{
			string fileName = "datafile/scorefile/scoreData.html";
			fs::path Path = fs::absolute(fileName);
			if (fs::exists(Path))
			{
				// スコアhtmlの表示(MS-EDGE用"start microsoft-edge:file://" + Path.string<char>();)
				const string s = "start firefox.exe \"" + Path.string<char>() + "\"";
				system(s.c_str());
			}
		}

		// 図鑑起動
		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_X) > 0) ||
			(JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_LEFT) > 20 
				&& JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_X) > 20))
		{
			string fileName =  "ステージ作成ツール.exe";
			fs::path Path = fs::absolute(fileName);
			if (fs::exists(Path))
			{
				// 図鑑の表示
				const string s = "start " + Path.string<char>();
				system(s.c_str());
			}
		}

		// アイテム編集画面
		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_Z) > 0)
			|| (JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_LEFT) > 20 
				&& JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_START) > 20))
		{
			BaseScene::nowScene = SceneName::eIC_Scene;
		}

		// debugモード切替処理
		if ((Keyboard::GetKey(KEY_INPUT_D) == 1 || JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_Y) == 1)
			&& !BaseScene::modeFlag)
		{
			if (modeCount < 5)
			{
				modeCount++;
			}
			else
			{
				BaseScene::modeFlag = true;
				ItemMgr::DebugMode();
			}
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

	// コメント切替カウンター
	if (cmtCounter < 256) { cmtCounter++; }
	else
	{
		cmtCounter = 0;
		if (cmtFlag == false) { cmtFlag = true; }
		else { cmtFlag = false; }
	}
}

void TitleScene::Draw() 
{
	// 背景・タイトル・コメントなど
	DrawGraph(0, 0, Graph::GetMainGraph(MG::mBack), true);
	DrawRotaGraph(900, 300, 1.5, 0.0, Graph::GetMainGraph(MG::mTitle), true);
	DrawGraph(700, 600, Graph::GetMainGraph(sele), true);
	DrawGraph(0, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawGraph(1920 - WALL_WIDTH, 0, Graphics::GetMainGraph(MG::mStoneWall), false);
	DrawExtendString(650, 960, 2.0, 2.0, "矢印キー↑↓で選択。Enterキーで決定。", 0xFFFFFF);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, cmtCounter);
	if (cmtFlag == false)
	{
		DrawExtendFormatString(300, 1020, 2.0, 2.0, 0xFFFFFF,
			"C + Z　でアイテム選択画面　C + S　でスコア表示　C + X　でステージ作成ツール起動");
	}
	else
	{
		DrawExtendFormatString(265, 1020, 2.0, 2.0, 0xFFFFFF,
			"← + START でアイテム選択画面　← + Y でスコア表示　← + X でステージ作成ツール起動");
	}
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	// 光量変化処理
	if (sceneFlag == true)
	{
		SetDrawBright(255 - BaseScene::counter, 255 - BaseScene::counter, 255 - BaseScene::counter);
	}
	else if (startFlag == true)
	{
		SetDrawBright(BaseScene::counter, BaseScene::counter, BaseScene::counter);
	}

	// debugモード時の確認表示
	if (BaseScene::modeFlag)
	{
		DrawBox(650, 60, 900, 96, 0xFFFFFF, true);
		DrawBoxAA(650.0f, 60.0f, 900.0f, 96.0f, 0x00FF00, false, 2.0f);
		DrawExtendFormatString(660, 64, 2.0, 2.0, 0x000000, "Debug Mode ON");
	}

#ifdef _DEBUG
	DrawFormatString(0, 0, 0xFFFFFF, "NowScene is Title\npless Enter to next");
	DrawFormatString(0, 32, 0xFFFFFF, "%d", BaseScene::counter);
	DrawFormatString(0, 64, 0xFFFFFF, sceneFlag ? "sceneFlag : true" : "sceneFlag : false");
	DrawFormatString(0, 96, 0xFFFFFF, startFlag ? "startFlag : true" : "startFlag : false");
#else
	if (BaseScene::modeFlag)
	{
		DrawFormatString(0, 0, 0xFFFFFF, "NowScene is Title\npless Enter to next");
		DrawFormatString(0, 32, 0xFFFFFF, "%d", BaseScene::counter);
		DrawFormatString(0, 64, 0xFFFFFF, sceneFlag ? "sceneFlag : true" : "sceneFlag : false");
		DrawFormatString(0, 96, 0xFFFFFF, startFlag ? "startFlag : true" : "startFlag : false");
	}
#endif // _DEBUG
}