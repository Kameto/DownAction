#pragma once

typedef enum ItemName
{
	IN_mCandela,	// カンデラ
	IN_mMask,		// マスク
	IN_A,			// 未実装
	IN_B,			// 未実装
	IN_C,			// 未実装
	mAll,
};

class ItemMgr
{
public:
	ItemMgr();
	~ItemMgr();
	static bool CheckItem();
	static bool* possItemFlag;		// アイテムフラグ
	static const int possItem = 5;	// アイテム所持数
	static bool possMaxFlag;
};