/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "BaseScene.h"
#include "Player.h"

class TitleScene
	: public BaseScene
{
public:
	TitleScene(); 
	~TitleScene();
	void Update();
	void Draw();

	int cmtCounter;	// コメント表示用カウンター
	int sele;		// 選択している項目変数
	int modeCount;	// debugモード管理カウント
	bool sceneFlag;	// フェード処理用フラグ
	bool startFlag;	// 
	bool cmtFlag;	// コメント表示用フラグ
};