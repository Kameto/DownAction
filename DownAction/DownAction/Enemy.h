#pragma once
#include "BaseObject.h"
class Enemy
	: public BaseObject
{
public:
	Enemy();
	Enemy(double _x, double _y);
	~Enemy();
	void Update();
	void Draw();
};