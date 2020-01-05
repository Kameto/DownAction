/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <DxLib.h>
#include "DefaultFunc.h"

class Camera
{
public:
	Camera();
	~Camera();
	void Update(double _x, double _y);
	void Draw();
	static double cx;
	static double cy;
	static double mx;
	static double my;
	const double stcx = 600.0;
	const double stcy = 640.0;
};