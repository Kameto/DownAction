/*
学籍番号：j17086
名前：亀田朋来
*/

#include <DxLib.h>
#include "SceneMgr.h"
#include "FPS.hpp"
#include "MyRand.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("DownAction");			// アプリケーション名

	SetOutApplicationLogValidFlag(false);		// logファイルの生成
#ifdef _DEBUG
	ChangeWindowMode(true);						// スクリーン設定
#else
	ChangeWindowMode(false);					// スクリーン設定
#endif
	SetGraphMode(1920, 1080, 32);				// 描画範囲
	SetFontSize(16);							// 文字サイズ設定
	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}
	SetMouseDispFlag(false);					// ウィンドウモードでもマウスカーソルを非表示にする

	Keyboard* key	 = new Keyboard();
	JoyPad* pad		 = new JoyPad();
	SceneMgr* smgr	 = new SceneMgr();
	MyRand* mrnd	 = new MyRand();

#ifdef _DEBUG
	FPS* fps		 = new FPS();
#endif // _DEBUG

	// メッセージループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_END) == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		key->KeyUpdate();
		pad->Pad_Update();
		smgr->SceneUpdate();
		smgr->SceneDraw();
		if (smgr->GetEndFlag() == true)
		{
			break;
		}
#ifdef _DEBUG
		//fps->Update();
		//fps->Draw();
		//fps->Waits();
#endif // _DEBUG
		ScreenFlip();
	}

#ifdef _DEBUG
	DEL_OBJ(fps);
#endif // _DEBUG

	DEL_OBJ(mrnd);
	DEL_OBJ(smgr);
	DEL_OBJ(pad);
	DEL_OBJ(key);

	InitGraph();
	DxLib_End();

	return 0;
}