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
	unsigned int bCount;// �u���b�N���߃J�E���g
	bool actionFlag;
	bool damegeFlag;
	bool fuwaFlag;
	bool kataFlag;
	bool blockFlag;// ���߂��Ă��邩���ʃt���O
};