/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <string>

class TimeWatch
{
public:
	TimeWatch();
	~TimeWatch();
	static void Update();
	static void ResetTimeWatch();
	static void StopTimeWatch();
	static void AddTime();
	static std::string GetTime();
	static int second;
	static double mSecond;

private:
	static int sum_Sec;
	static double sum_MSec;
	static bool tFlag;
};