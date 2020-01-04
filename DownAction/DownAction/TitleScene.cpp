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
	if (sceneFlag == false && endFlag == false && startFlag == false)
	{
		// �J�ڐ挈��
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

		// �J�ڐ�ؑ�
		if (Keyboard::GetKey(KEY_INPUT_UP) == 1)
		{
			sele = MG::mStart;
		}
		else if (Keyboard::GetKey(KEY_INPUT_DOWN) == 1)
		{
			sele = MG::mEnd;
		}
		
		// �X�R�A�Q��
		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_S) > 0) || 
			(JoyPad::Button_Get(PLAY_NUM_1 ,XINPUT_BUTTON_DPAD_LEFT) > 20 && JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_RIGHT_SHOULDER) > 20))
		{
			string fileName = "datafile/scorefile/scoreData.html";
			fs::path Path = fs::absolute(fileName);
			if (fs::exists(Path))
			{
				// �X�R�Ahtml�̕\��
				const string s = "start firefox.exe \"" + Path.string<char>() + "\"";
				system(s.c_str());
			}
			else
			{

			}
		}

		// �}�ӋN��
		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_X) > 0) ||
			(JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_LEFT) > 20 && JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_LEFT_SHOULDER) > 20))
		{
			string fileName =  "PictureBook.exe";
			fs::path Path = fs::absolute(fileName);
			if (fs::exists(Path))
			{
				// �}�ӂ̕\��
				const string s = "start " + Path.string<char>();
				system(s.c_str());
			}
			else
			{

			}
		}

		if ((Keyboard::GetKey(KEY_INPUT_C) > 0 && Keyboard::GetKey(KEY_INPUT_Z) > 0) ||
			(JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_DPAD_LEFT) > 20 && JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_START) > 20))
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


	if (cmtCounter < 256)
	{
		cmtCounter++;
	}
	else
	{
		cmtCounter = 0;
		if (cmtFlag == false)
		{
			cmtFlag = true;
		}
		else
		{
			cmtFlag = false;
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

	DrawExtendString(650, 960, 2.0, 2.0, "���L�[�����őI���BEnter�L�[�Ō���B", 0xFFFFFF);
	
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, cmtCounter);
	if (cmtFlag == false)
	{
		DrawExtendFormatString(300, 1020, 2.0, 2.0, 0xFFFFFF, "C + Z�@�ŃA�C�e���I����ʁ@C + S�@�ŃX�R�A�\���@C + X�@�ŉ��y�v���[���[�N��");
	}
	else
	{
		DrawExtendFormatString(265, 1020, 2.0, 2.0, 0xFFFFFF, "�� + START �ŃA�C�e���I����ʁ@�� + L1 �ŃX�R�A�\���@�� + R1 �ŉ��y�v���[���[�N��");
	}
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

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