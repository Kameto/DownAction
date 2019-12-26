#include "BaseScene.h"

SceneName BaseScene::nowScene = SceneName::eTitle;
bool BaseScene::endFlag = false;
int BaseScene::counter = 0;
int BaseScene::nowStage = 0;
int BaseScene::stageNum = 3;
bool BaseScene::firstFlag = true;

SceneName BaseScene::GetNowScene()
{
	return nowScene;
}

void BaseScene::FadeOut(SceneName nextScene)
{
	if (counter < 385)
	{
		counter += 5;
	}
	else
	{
		counter = 0;
		nowScene = nextScene;
	}
}

void BaseScene::FadeIn()
{
	if (counter < 256)
	{
		counter++;
	}
}

void BaseScene::EndInput()
{
	if (Keyboard::GetKey(KEY_INPUT_ESCAPE) > 0 ||
		(JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_START) > 0 && JoyPad::Button_Get(PLAY_NUM_1, XINPUT_BUTTON_BACK) > 0))
	{
		endFlag = true;
	}
}