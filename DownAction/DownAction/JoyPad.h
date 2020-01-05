/*
�w�Дԍ��Fj17086
���O�F�T�c����
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
	static void Pad_Update	(void											);		// �X�V
	static int	Button_Get	(int player, int BtCode			);						// �{�^�����̎󂯎��
	static int	Trigger_Get	(int player, int TrCode							);		// �g���K�[�̎󂯎��
	static int	Stick_Get	(int player, int StCode, int x_y				);		// �X�e�B�b�N�̎󂯎��
	static void Reset		(int player, char input, int code, int x_y = 0	);		// ���͏�Ԃ̃��Z�b�g

private:
	static XINPUT_STATE P_STATE[2];	// ���͏��
	static int Bt[2][16];			// �{�^��	(�R���g���[���ԍ��A���)
	static int Tr[2][2];			// �g���K�[	(�R���g���[���ԍ��A���E)
	static int St[2][2][4];			// �X�e�B�b�N(�R���g���[���ԍ��A�ǂ���̃X�e�B�b�N���A���͕���)
};	