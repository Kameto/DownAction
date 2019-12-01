#pragma once
#include "BaseObject.h"

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
	int counter[3];
	bool actionFlag;
	bool damegeFlag;
	bool fuwaFlag;
	bool kataFlag;
};