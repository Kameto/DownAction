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
	int rand;
	bool sceneFlag;
};