#pragma once
#include "BaseObject.h"
class Block
	: public BaseObject
{
public:
	Block();
	Block(double _x, double _y);
	~Block();
	void Update();
	void Draw();
};