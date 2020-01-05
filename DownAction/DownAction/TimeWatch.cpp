/*
学籍番号：j17086
名前：亀田朋来
*/

#include "TimeWatch.h"

TimeWatch::TimeWatch()
{
	second	 = 0;
	mSecond	 = -1.0;
	tFlag	 = true;
}

TimeWatch::~TimeWatch()
{
	second = 0;
	mSecond = 0.0;
	tFlag = false;
}

void TimeWatch::Update()
{
	if (tFlag == true)
	{
		if (mSecond == 59)
		{
			mSecond = 0.0;
			second++;
		}
		else
		{
			mSecond++;
		}
	}
}

std::string TimeWatch::GetTime()
{
	std::string str;
	str += std::to_string(second) + "." + std::to_string((int)mSecond);
	return str;
}