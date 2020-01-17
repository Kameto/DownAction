/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <filesystem>
#include <tchar.h>
#include <process.h>
#include "Graphics.h"
#include "ItemMgr.h"
#include "JoyPad.h"
#include "Keyboard.h"

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
	SceneName GetNowScene();	// 現在シーンの取得
	void EndInput();			// 終了コマンド関数
	static bool endFlag;		// 終了フラグ

protected:
	void FadeOut(SceneName);	// フェードイン関数
	void FadeIn();				// フェードアウト関数
	static SceneName nowScene;	// 現在シーン
	static bool firstFlag;		// 初回起動フラグ
	static bool modeFlag;		// debugモードフラグ
	static int counter;			// 画面遷移時に使用するカウンター
	static int nowStage;		// ゲーム時のステージカウント
	static int stageNum;		// ゲーム時の最大ステージ数
};