/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#pragma once

typedef enum class ItemName
{
	IN_mCandela,	// �J���f��
	IN_mMask,		// �}�X�N
	IN_mCrystal,	// �����̃l�b�N���X
	IN_mMap,		// ��̒n�}
	IN_mPortal,		// �]�ڃ|�[�^��
	IN_mMagia,		// ���@�̖{
	IN_mPaper,		// ���D
	IN_mKnife,		// �i�C�t
	IN_mMusicPlayer,// ���y�v���[���[
	IN_mPorsion,	// �ہ[������
	mAll
}IName;

class ItemMgr
{
public:
	ItemMgr();
	~ItemMgr();
	static bool CheckItem();
	static bool* possItemFlag;		// �A�C�e���t���O
	static const int possItem = 3;	// �A�C�e��������
	static bool possMaxFlag;		// ����܂ŃA�C�e���������Ă��邩�m�F�t���O
	static int* setItem;			// �����A�C�e���Q�ƕϐ�
};