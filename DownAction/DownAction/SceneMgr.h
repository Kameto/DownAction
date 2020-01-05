/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "GameScene.h"		// GameScene,Graphics,Keyboard,DataFile,Score
#include "ResultScene.h"	// ResulScene,Graphics,Keyboard,DataFile,Score
#include "ResultScene2.h"	// ResulScene2,Graphics,Keyboard,DataFile,Score
#include "TitleScene.h"		// TitleScene,Graphics,Keyboard
#include "ItemChangeScene.h"// IC_Scene, Graphics, Keyboard, Mouse, ItemMgr

class SceneMgr
{
public:
	SceneMgr(); 
	~SceneMgr();

 	void ChangeScene();
	void SceneUpdate();
	void SceneDraw();
	bool GetEndFlag();

private:
	BaseScene* mpScene;	// シーン用ポインター
	SceneName preScene;	// 前シーン記憶メンバ
	Graphics* gra;		// 画像クラスポインター
	DataFile* df;		// ファイル関連クラスポインター
	Score* sc;			// ゲーム内スコアクラスポインター
	ItemMgr* imgr;		// プレイヤーアイテム管理クラスポインター
};