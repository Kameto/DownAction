#pragma once
#include <DxLib.h>
#include <string>
#include <vector>

// main�t�H���_���摜��
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
	mItemBox,	// �A�C�e���{�b�N�X
	mCandela,	// �J���f��
	mMask,		// �}�X�N
	mCrystal,	// �����̃l�b�N���X
	mMap,		// ��̒n�}
	mPortal,	// �]�ڃ|�[�^��
	mMagia,		// ���@�̖{
	mPaper,		// ���D
	mKnife,		// �i�C�t
	mMusicPlayer,// ���y�v���[���[
	mAll_num	// ����
}MG;

// �L�����N�^�[���
typedef enum Chara_State
{
	mNomal,		// �ʏ펞
	mDown,		// ������
	mDamage,	// ��e��
	mKatai,		// �J�`�J�`���[�h
	mFuwafuwa,	// �ӂ�ӂ탂�[�h
	mCnum		// ����
}CS;

enum Moji
{
	mDoxuru,	// �h�D������
	mDen,		// �f��
	mMoji_All
};

class Graphics
{
public:
	Graphics();
	~Graphics();

	/*** ThisScene ***/
	// ���[�h����
	static void LoadMainGraph();
	static void LoadPlayerGraph();
	static void LoadEnemyGraph();
	static void LoadCrystalGraph();
	static void LoadMojiGraph();

	// �擾����
	static int GetMainGraph(int);
	static int GetPlayerGraph(int);
	static int GetEnemyGraph(int);
	static int GetCrystalGraph(int);
	static int GetMojiGraph(int);
	/*****************/

private:
	/*** static ***/
	static int m_gr[MG::mAll_num];
	static int p_gr[CS::mCnum];
	static int e_gr[CS::mCnum];
	static int b_gr[6];
	static int mo_gr[Moji::mMoji_All];
	/**************/
};
typedef Graphics Graph;