/*
�w�Дԍ��Fj17086
���O�F�T�c����
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
	//1�t���[���ڂȂ玞�����L��
	if (mCount == 0) {
		mStartTime = GetNowCount();
	}

	//60�t���[���ڂȂ畽�ς��v�Z����
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
	int tookTime = GetNowCount() - mStartTime;		//������������
	int waitTime = mCount * 1000 / Fps - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);							//�ҋ@
	}
}