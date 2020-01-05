/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "BaseScene.h"
#include "DataFile.h"
#include "MyRand.h"

class ResultScene
	: public BaseScene
{
public:
	ResultScene(); 
	~ResultScene();
	void Update();
	void Draw();

private:
	int counter[4];
	int rand[2];
	bool sceneFlag;
	bool checkFlag;
};