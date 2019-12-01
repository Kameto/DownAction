#pragma once
#include <random>
class MyRand
{
public:
	MyRand();
	MyRand(int _min, int _max);
	~MyRand();
	static int inline GetRand()
	{
		std::random_device rnd;
		std::mt19937 mt(rnd());
		static std::uniform_int_distribution<> rnds(rndMin, rndMax);
		return rnds(mt);
	}
	static void SetSW(int _min, int _max);

private:
	static int rndMin;
	static int rndMax;
};