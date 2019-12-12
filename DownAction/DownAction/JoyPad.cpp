#include "JoyPad.h"

XINPUT_STATE JoyPad::P_STATE[2];
int JoyPad::Bt[2][16];
int JoyPad::Tr[2][2];
int JoyPad::St[2][2][4];


JoyPad::JoyPad()
{
	// どうせ触らなくてもUpdateで0になるけど一応
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			Bt[i][j] = 0;
		}
		for (int j = 0; j < 2; j++)
		{
			Tr[i][j] = 0;
		}
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				St[i][j][k] = 0;
			}
		}
	}
}

// 特になし
JoyPad::~JoyPad(){}

void JoyPad::Pad_Update(void)
{
	// 入力状態を受け取る
	for (int i = 0; i < 2; i++)
	{
		GetJoypadXInputState(i+1, &P_STATE[i]);

		// ボタン処理
		for (int j = 0; j < 16; j++)
		{
			// プレイヤー1のi番目のボタンが押されていたら
			if (P_STATE[i].Buttons[j] == 1) Bt[i][j]++;	// 押されているだけカウンタを上げる
			else if (Bt[i][j]>0) Bt[i][j] = -1;			// 離された瞬間にカウンタを-1にする
			else Bt[i][j] = 0;							// 離されたらカウンタを0に戻す		
		}

		// トリガー処理
		{		
			if (P_STATE[i].LeftTrigger >= 128) Tr[i][0]++;		// 左トリガーが半分以上押し込まれていたらカウントを上げる。
			else Tr[i][0] = 0;									// それ以外ならカウントをリセット
			if (P_STATE[i].RightTrigger >= 128) Tr[i][1]++;		// 右トリガーが半分以上押し込まれていたらカウントを上げる。
			else Tr[i][1] = 0;									// リセット
		}

		// スティック処理
		// 共通処理で5割以上倒れていたらカウンタを上げる(if文)、倒れていないならカウンタを0にする(else文)
		// 反動で行きすぎない対策のつもりだがまた改めて治すかも
		{
			// 左スティック右
			if (P_STATE[i].ThumbLX >= 16384) St[i][LSTICK][RIGHT]++;		
			else St[i][LSTICK][RIGHT] = 0;

			// 左スティック左
			if (P_STATE[i].ThumbLX <= -16384) St[i][LSTICK][LEFT]++;
			else St[i][LSTICK][LEFT] = 0;

			// 左スティック上
			if (P_STATE[i].ThumbLY >= 16384) St[i][LSTICK][UP]++;
			else St[i][LSTICK][UP] = 0;

			// 左スティック下
			if (P_STATE[i].ThumbLY <= -16384) St[i][LSTICK][DOWN]++;
			else St[i][LSTICK][DOWN] = 0;

			// 右スティック右
			if (P_STATE[i].ThumbRX >= 16384) St[i][RSTICK][RIGHT]++;
			else St[i][RSTICK][RIGHT] = 0;							

			// 右スティック左
			if (P_STATE[i].ThumbRX <= -16384) St[i][RSTICK][LEFT]++;
			else St[i][RSTICK][LEFT] = 0;
			// 右スティック上
			if (P_STATE[i].ThumbRY >= 16384) St[i][RSTICK][UP]++;
			else St[i][RSTICK][UP] = 0;								

			// 右スティック下
			if (P_STATE[i].ThumbRY <= -16384) St[i][RSTICK][DOWN]++;
			else St[i][RSTICK][DOWN] = 0;									
		}
		
	}
}

// ボタンゲッタ(そのままプレイヤー番号を入れるため入力ミスに注意)
int JoyPad::Button_Get(int player, int BtCode)
{
	return Bt[--player][BtCode];
}
// トリガゲッタ(入力ミスに注意)
int JoyPad::Trigger_Get(int player, int TrCode)
{
	return Tr[--player][TrCode];
}
// スティックゲッタ(入力ミスに注意、第3引数はx方向かy方向を入れる)
int JoyPad::Stick_Get(int player, int StCode, int x_y)
{
	return St[--player][StCode][x_y];
}

void JoyPad::Reset(int player, char input, int code, int x_y)
{
	switch (input)
	{
	case 'B':
		Bt[--player][code] = 0;
		break;

	case 'T':
		Tr[--player][code] = 0;
		break;

	case 'S':
		St[--player][code][x_y] = 0;
		break;

	default:
		break;
	}
}
