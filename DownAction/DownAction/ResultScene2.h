/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "BaseScene.h"
#include "MyRand.h"

class ResultScene2 :
	public BaseScene
{
public:
	ResultScene2();
	~ResultScene2();
	void Update();
	void Draw();

private:
	int counter[4];
	int rand;
	bool sceneFlag;
	bool moveFlag;
	bool checkFlag;
};