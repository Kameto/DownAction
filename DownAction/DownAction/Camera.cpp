/*
学籍番号：j17086
名前：亀田朋来
*/

#include "Camera.h"

double Camera::cx;
double Camera::cy;
double Camera::mx;
double Camera::my;

Camera::Camera()
{
	cx = 600;
	cy = 0;
	mx = 0;
	my = 0;
}

Camera::~Camera()
{
	cx = 0;
	cy = 0;
	mx = 0;
	my = 0;
}

void Camera::Update(double _x, double _y)
{
	cx = _x;
	cy = _y;
	mx = cx - stcx;
	my = cy - stcy;
}

void Camera::Draw()
{
	DrawBox(stcx - 128, stcy - 128, stcx + 128, stcy + 128, 0x0000FF, false);
}