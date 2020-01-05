/*
学籍番号：j17086
名前：亀田朋来
*/

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