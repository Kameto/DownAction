#pragma once

typedef enum class ItemName
{
	IN_mCandela,	// �J���f��
	IN_mMask,		// �}�X�N
	IN_mCrystal,	// �����̃l�b�N���X
	IN_mMap,		// ��̒n�}
	IN_C,			// ������
	mAll,
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
	static int* setItem;			// �����A�C�e���Q�Ɓ@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�ϐ�
};