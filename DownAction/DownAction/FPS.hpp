/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#pragma once
#include "DxLib.h"

// FPS�ϑ��p�N���X
class FPS
{
public:
	FPS();				// �R���X�g���N�^
	~FPS();				// �f�X�g���N�^
	void Update();		// ����
	void Draw();		// �`��
	void Waits();		// �҂�����S

private:
	int mStartTime;		// �v�Z�p�ϐ�1
	int mCount;			// �v�Z�p�ϐ�2
	int mT;				// �v�Z�p�ϐ�3
	float mFps;			// �v�Z�p�ϐ�4
	const int N = 60;	// �b��
	const int Fps = 60;	// �Œ肵��FPS
};