#pragma once
#include <DxLib.h>
#include <string>
#include <vector>

typedef enum MainGraphs
{
	mTitle,		// �^�C�g��
	mFrame,		// ��ʃt���[��
	mBack,		// �w�i
	mStart,		// �I�����i�J�n�j
	mEnd,		// �I�����i�I���j
	mItem,		// �A�C�e��
	mGauge,		// �G�l���M�[�Q�[�W
	mGameOver,	// �Q�[���I�[�o�[
	mGameClear,	// �Q�[���N���A
	mChange,	// �ϐg�g
	mStick,		// �X�e�B�b�N
	mChain,		// ��
	mKeyLock,	// ���O
	mComent,	// �R�����g�g
	mStoneWall,	// ���
	mBlock,		// ����
	mAlter,		// �Ւd
	mBox,		// ��
	mComment2,	// �����o��
	mAll_num	// ����
}MG;

typedef enum Chara_State
{
	mNomal,		// �ʏ펞
	mDown,		// ������
	mDamage,	// ��e��
	mKatai,		// �J�`�J�`���[�h
	mFuwafuwa,	// �ӂ�ӂ탂�[�h
	mCnum		// ����
}CS;

class Graphics
{
public:
	Graphics();
	~Graphics();

	// ���[�h����
	static void LoadMainGraph();
	static void LoadPlayerGraph();
	static void LoadEnemyGraph();
	static void LoadCrystalGraph();

	// �擾����
	static int GetMainGraph(int);
	static int GetPlayerGraph(int);
	static int GetEnemyGraph(int);
	static int GetCrystalGraph(int);

private:
	static int m_gr[MG::mAll_num];
	static int p_gr[CS::mCnum];
	static int e_gr[CS::mCnum];
	static int b_gr[6];
};

typedef Graphics Graph;