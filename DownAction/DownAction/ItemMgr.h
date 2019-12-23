#pragma once

typedef enum class ItemName
{
	IN_mCandela,	// カンデラ
	IN_mMask,		// マスク
	IN_mCrystal,	// 水晶のネックレス
	IN_mMap,		// 宝の地図
	IN_C,			// 未実装
	mAll,
}IName;

class ItemMgr
{
public:
	ItemMgr();
	~ItemMgr();
	static bool CheckItem();
	static bool* possItemFlag;		// アイテムフラグ
	static const int possItem = 3;	// アイテム所持数
	static bool possMaxFlag;		// 上限までアイテムを持っているか確認フラグ
	static int* setItem;			// 所持アイテム参照　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　変数
};