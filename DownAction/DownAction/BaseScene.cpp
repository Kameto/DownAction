#include "BaseScene.h"

SceneName BaseScene::nowScene = SceneName::eTitle;
bool BaseScene::endFlag = false;
bool BaseScene::firstFlag = true;
int BaseScene::counter = 0;

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