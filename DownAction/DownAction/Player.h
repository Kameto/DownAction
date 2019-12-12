#pragma once
#include "BaseObject.h"
#include "ItemMgr.h"
#include "JoyPad.h"

typedef enum class Direction
{
	mRight, mLeft, mNone
}Dir;

class Player
	: public BaseObject
{
public:
	Player(); 
	~Player();
	void Update();
	void StateUpdate();
	void Draw();
	Dir dir;
	static int enegy;
	int life;
	int counter[4];
	unsigned int bCount;// ブロック透過カウント
	bool actionFlag;
	bool damegeFlag;
	bool fuwaFlag;
	bool kataFlag;
	bool blockFlag;// 透過しているか判別フラグ
};