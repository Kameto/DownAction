/*
�w�Дԍ��Fj17086
���O�F�T�c����
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