#pragma once
#include "BaseScene.h"
#include "ItemMgr.h"

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

private:
	int nowItem[3];
	bool cFlag;
};
typedef ItemChangeScene IC_Scene;