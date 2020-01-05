/*
学籍番号：j17086
名前：亀田朋来
*/

#include "MyRand.h"

int MyRand::rndMin;
int MyRand::rndMax;

MyRand::MyRand()
{
	rndMin = 0;
	rndMax = 715000;
}

MyRand::MyRand(int _min, int _max)
{
	rndMin = _min;
	rndMax = _max;
}

MyRand::~MyRand()
{
	rndMin = 0;
	rndMax = 0;
}

void MyRand::SetSW(int _min, int _max)
{
	rndMin = _min;
	rndMax = _max;
}