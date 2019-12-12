#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "ItemMgr.h"

enum class SceneName
{
	eTitle,
	eGame,
	eResult
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
	static SceneName nowScene;
	static bool firstFlag;
	static int counter;
};