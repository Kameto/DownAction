/*
学籍番号：j17086
名前：亀田朋来
*/

#include "TimeWatch.h"

int TimeWatch::sum_Sec;
int TimeWatch::second;
double TimeWatch::sum_MSec;
double TimeWatch::mSecond;
bool TimeWatch::tFlag;

TimeWatch::TimeWatch()
{
	sum_Sec = 0;
	sum_MSec = 0.0;
	second	 = 0;
	mSecond	 = -1.0;
	tFlag	 = true;
}

TimeWatch::~TimeWatch()
{
	sum_Sec = 0;
	sum_MSec = 0.0;
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

void TimeWatch::ResetTimeWatch()
{
	second = 0;
	mSecond = -1.0;
	tFlag = true;
}

void TimeWatch::StopTimeWatch()
{
	tFlag = false;
}

void TimeWatch::AddTime()
{
	sum_Sec += second;
	sum_MSec += mSecond;
}

std::string TimeWatch::GetTime()
{
	std::string str;
	str += std::to_string(sum_Sec) + "." + std::to_string((int)sum_MSec);
	return str;
}