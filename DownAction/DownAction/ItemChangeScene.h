#pragma once
#include "BaseScene.h"
#include "ItemMgr.h"

typedef struct MoveRange
{
	int min;
	int max;
}MRange;

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
	const MRange widR{ 0, 4 };
	const MRange heiR{ 0, (((int)ItemName::mAll) % widR.max) - 1 };
	int nWid;
	int nHei;
	int changeItem;
};
typedef ItemChangeScene IC_Scene;