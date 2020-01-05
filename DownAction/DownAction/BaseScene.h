/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <filesystem>
#include <tchar.h>
#include <process.h>
#include "Keyboard.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "JoyPad.h"

using namespace std;
namespace fs = filesystem;

enum class SceneName
{
	eTitle,		// タイトル
	eIC_Scene,	// アイテム変更
	eGame,		// ゲーム
	eResult,	// リザルト
	eResult2	// 途中リザルト
};

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	SceneName GetNowScene();
	void EndInput();
	static bool endFlag;

protected:
	void FadeOut(SceneName);
	void FadeIn();
	static SceneName nowScene;
	static bool firstFlag;
	static int counter;
	static int nowStage;
	static int stageNum;
};