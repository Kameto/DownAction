/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "DxLib.h"

#define PLAY_NUM_1 0x01
#define PLAY_NUM_2 0x02

#define LSTICK 0x00
#define RSTICK 0x01

#define RIGHT 0x00
#define DOWN 0x01
#define LEFT 0x02
#define UP 0x03

class JoyPad
{
public:
	JoyPad(); 
	~JoyPad();
	static void Pad_Update	(void											);		// 更新
	static int	Button_Get	(int player, int BtCode			);						// ボタン情報の受け取り
	static int	Trigger_Get	(int player, int TrCode							);		// トリガーの受け取り
	static int	Stick_Get	(int player, int StCode, int x_y				);		// スティックの受け取り
	static void Reset		(int player, char input, int code, int x_y = 0	);		// 入力状態のリセット

private:
	static XINPUT_STATE P_STATE[2];	// 入力状態
	static int Bt[2][16];			// ボタン	(コントローラ番号、種類)
	static int Tr[2][2];			// トリガー	(コントローラ番号、左右)
	static int St[2][2][4];			// スティック(コントローラ番号、どちらのスティックか、入力方向)
};	