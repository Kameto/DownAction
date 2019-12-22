#pragma once
#include "BaseScene.h"
class ItemChangeScene :
	public BaseScene
{
public:
	ItemChangeScene();
	~ItemChangeScene();
	void Update();
	void Draw();
	void UI_Update();
	void UI_Draw();
};
typedef ItemChangeScene IC_Scene;