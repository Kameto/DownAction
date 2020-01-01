#pragma once
#include <process.h>
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