/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "BaseObject.h"
class Item
	: public BaseObject
{
public:
	Item(); 
	Item(double _x, double _y);
	~Item();
	void Update();
	void Draw();
};