/*
�w�Дԍ��Fj17086
���O�F�T�c����
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