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
	void Update();
	std::string GetTime();

	int second;
	double mSecond;
	bool tFlag;
};