#pragma once

typedef enum ItemName
{
	IN_mCandela,	// �J���f��
	IN_mMask,		// �}�X�N
	IN_A,			// ������
	IN_B,			// ������
	IN_C,			// ������
	mAll,
};

class ItemMgr
{
public:
	ItemMgr();
	~ItemMgr();
	static bool CheckItem();
	static bool* possItemFlag;		// �A�C�e���t���O
	static const int possItem = 5;	// �A�C�e��������
	static bool possMaxFlag;
};