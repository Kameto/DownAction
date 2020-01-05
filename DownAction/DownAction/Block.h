/*
学籍番号：j17086
名前：亀田朋来
*/

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

	bool transFlag;
};