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