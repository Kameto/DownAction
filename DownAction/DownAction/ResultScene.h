/*
�w�Дԍ��Fj17086
���O�F�T�c����
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