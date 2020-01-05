/*
学籍番号：j17086
名前：亀田朋来
*/

#include "FPS.hpp"

FPS::FPS()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
	mT = 0;
}

FPS::~FPS()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
	mT = 0;
}

void FPS::Update()
{
	//1フレーム目なら時刻を記憶
	if (mCount == 0) {
		mStartTime = GetNowCount();
	}

	//60フレーム目なら平均を計算する
	if (mCount == N) {
		mT = GetNowCount();
		mFps = 1000.f / ((mT - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = mT;
	}
	mCount++;
}

void FPS::Draw()
{
	DrawFormatString(900, 0, 0xDD77DD, "FPS : %.3f", mFps);
}

void FPS::Waits()
{
	int tookTime = GetNowCount() - mStartTime;		//かかった時間
	int waitTime = mCount * 1000 / Fps - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);							//待機
	}
}