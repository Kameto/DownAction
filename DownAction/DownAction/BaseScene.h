#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "JoyPad.h"

enum class SceneName
{
	eTitle,
	eGame,
	eResult,
	eResult2,
	eIC_Scene
};

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	SceneName GetNowScene();
	static bool endFlag;

protected:
	void FadeOut(SceneName);
	void FadeIn();
	void EndInput();
	static SceneName nowScene;
	static bool firstFlag;
	static int counter;
	static int nowStage;
	static int stageNum;
};