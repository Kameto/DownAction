/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once

typedef enum class ItemName
{
	IN_mCandela,	// カンデラ
	IN_mMask,		// マスク
	IN_mCrystal,	// 水晶のネックレス
	IN_mMap,		// 宝の地図
	IN_mPortal,		// 転移ポータル
	IN_mMagia,		// 魔法の本
	IN_mPaper,		// お札
	IN_mKnife,		// ナイフ
	IN_mMusicPlayer,// 音楽プレーヤー
	IN_mPorsion,	// ぽーしぉん
	mAll
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
	static int* setItem;			// 所持アイテム参照変数
};