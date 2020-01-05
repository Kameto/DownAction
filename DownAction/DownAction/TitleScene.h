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

	int cmtCounter;
	int sele;
	bool sceneFlag;
	bool startFlag;
	bool cmtFlag;
};