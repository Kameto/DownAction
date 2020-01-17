/*
学籍番号：j17086
名前：亀田朋来
*/

#include "BaseScene.h"

SceneName BaseScene::nowScene = SceneName::eTitle;
bool BaseScene::endFlag = false;
bool BaseScene::modeFlag = false;
int BaseScene::counter = 0;
int BaseScene::nowStage = 0;
int BaseScene::stageNum = 3;

#ifdef _DEBUG
bool BaseScene::firstFlag = false;
#else
bool BaseScene::firstFlag = true;
#endif

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