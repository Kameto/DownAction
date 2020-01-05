/*
学籍番号：j17086
名前：亀田朋来
*/

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
	/*** BaseScene ***/
	ItemChangeScene();
	~ItemChangeScene();
	void Update();
	void Draw();
	/*****************/

	/*** ThisScene ***/
	void UI_Update();
	void UI_Draw();
	/*****************/
private:
	
	/***  local ***/
	int nWid;
	int nHei;
	int changeItem;
	int nowItem[3];
	const int tp[2][2] = { { 900, 350}, { 900, 750} };// { x, y}
	bool cFlag;
	const MRange widR{ 0, 4 };
	const MRange heiR{ 0, (((int)ItemName::mAll) / widR.max) - 1 };
	/**************/
};
typedef ItemChangeScene IC_Scene;