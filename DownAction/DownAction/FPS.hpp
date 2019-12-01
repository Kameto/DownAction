#pragma once
#include "DxLib.h"

// FPS観測用クラス
class FPS
{
public:
	FPS();				// コンストラクタ
	~FPS();				// デストラクタ
	void Update();		// 処理
	void Draw();		// 描画
	void Waits();		// 待ち時間S

private:
	int mStartTime;		// 計算用変数1
	int mCount;			// 計算用変数2
	int mT;				// 計算用変数3
	float mFps;			// 計算用変数4
	const int N = 60;	// 秒数
	const int Fps = 60;	// 固定したFPS
};