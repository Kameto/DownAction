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