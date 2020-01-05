/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#include "JoyPad.h"

XINPUT_STATE JoyPad::P_STATE[2];
int JoyPad::Bt[2][16];
int JoyPad::Tr[2][2];
int JoyPad::St[2][2][4];


JoyPad::JoyPad()
{
	// �ǂ����G��Ȃ��Ă�Update��0�ɂȂ邯�ǈꉞ
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

// ���ɂȂ�
JoyPad::~JoyPad(){}

void JoyPad::Pad_Update(void)
{
	// ���͏�Ԃ��󂯎��
	for (int i = 0; i < 2; i++)
	{
		GetJoypadXInputState(i+1, &P_STATE[i]);

		// �{�^������
		for (int j = 0; j < 16; j++)
		{
			// �v���C���[1��i�Ԗڂ̃{�^����������Ă�����
			if (P_STATE[i].Buttons[j] == 1) Bt[i][j]++;	// ������Ă��邾���J�E���^���グ��
			else if (Bt[i][j]>0) Bt[i][j] = -1;			// �����ꂽ�u�ԂɃJ�E���^��-1�ɂ���
			else Bt[i][j] = 0;							// �����ꂽ��J�E���^��0�ɖ߂�		
		}

		// �g���K�[����
		{		
			if (P_STATE[i].LeftTrigger >= 128) Tr[i][0]++;		// ���g���K�[�������ȏ㉟�����܂�Ă�����J�E���g���グ��B
			else Tr[i][0] = 0;									// ����ȊO�Ȃ�J�E���g�����Z�b�g
			if (P_STATE[i].RightTrigger >= 128) Tr[i][1]++;		// �E�g���K�[�������ȏ㉟�����܂�Ă�����J�E���g���グ��B
			else Tr[i][1] = 0;									// ���Z�b�g
		}

		// �X�e�B�b�N����
		// ���ʏ�����5���ȏ�|��Ă�����J�E���^���グ��(if��)�A�|��Ă��Ȃ��Ȃ�J�E���^��0�ɂ���(else��)
		// �����ōs�������Ȃ��΍�̂��肾���܂����߂Ď�������
		{
			// ���X�e�B�b�N�E
			if (P_STATE[i].ThumbLX >= 16384) St[i][LSTICK][RIGHT]++;		
			else St[i][LSTICK][RIGHT] = 0;

			// ���X�e�B�b�N��
			if (P_STATE[i].ThumbLX <= -16384) St[i][LSTICK][LEFT]++;
			else St[i][LSTICK][LEFT] = 0;

			// ���X�e�B�b�N��
			if (P_STATE[i].ThumbLY >= 16384) St[i][LSTICK][UP]++;
			else St[i][LSTICK][UP] = 0;

			// ���X�e�B�b�N��
			if (P_STATE[i].ThumbLY <= -16384) St[i][LSTICK][DOWN]++;
			else St[i][LSTICK][DOWN] = 0;

			// �E�X�e�B�b�N�E
			if (P_STATE[i].ThumbRX >= 16384) St[i][RSTICK][RIGHT]++;
			else St[i][RSTICK][RIGHT] = 0;							

			// �E�X�e�B�b�N��
			if (P_STATE[i].ThumbRX <= -16384) St[i][RSTICK][LEFT]++;
			else St[i][RSTICK][LEFT] = 0;
			// �E�X�e�B�b�N��
			if (P_STATE[i].ThumbRY >= 16384) St[i][RSTICK][UP]++;
			else St[i][RSTICK][UP] = 0;								

			// �E�X�e�B�b�N��
			if (P_STATE[i].ThumbRY <= -16384) St[i][RSTICK][DOWN]++;
			else St[i][RSTICK][DOWN] = 0;									
		}
		
	}
}

// �{�^���Q�b�^(���̂܂܃v���C���[�ԍ������邽�ߓ��̓~�X�ɒ���)
int JoyPad::Button_Get(int player, int BtCode)
{
	return Bt[--player][BtCode];
}
// �g���K�Q�b�^(���̓~�X�ɒ���)
int JoyPad::Trigger_Get(int player, int TrCode)
{
	return Tr[--player][TrCode];
}
// �X�e�B�b�N�Q�b�^(���̓~�X�ɒ��ӁA��3������x������y����������)
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
