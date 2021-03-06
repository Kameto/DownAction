/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <DxLib.h>
#include <string>
#include <vector>

// mainフォルダ内画像名
typedef enum MainGraphs
{
	mTitle,		// タイトル
	mFrame,		// 画面フレーム
	mBack,		// 背景
	mStart,		// 選択肢（開始）
	mEnd,		// 選択肢（終了）
	mItem,		// アイテム
	mGauge,		// エネルギーゲージ
	mGameOver,	// ゲームオーバー
	mGameClear,	// ゲームクリア
	mChange,	// 変身枠
	mStick,		// スティック
	mChain,		// 鎖
	mKeyLock,	// 錠前
	mComent,	// コメント枠
	mStoneWall,	// 岩壁
	mBlock,		// 足場
	mAlter,		// 祭壇
	mBox,		// 宝箱
	mComment2,	// 吹き出し
	mItemBox,	// アイテムボックス
	mCandela,	// カンデラ
	mMask,		// マスク
	mCrystal,	// 水晶のネックレス
	mMap,		// 宝の地図
	mPortal,	// 転移ポータル
	mMagia,		// 魔法の本
	mPaper,		// お札
	mKnife,		// ナイフ
	mMusicPlayer,// 音楽プレーヤー
	mPorsion,	// ぽーしぉん
	mAll_num	// 総数
}MG;

// キャラクター状態
typedef enum Chara_State
{
	mNomal,		// 通常時
	mDown,		// 落下時
	mDamage,	// 被弾時
	mKatai,		// カチカチモード
	mFuwafuwa,	// ふわふわモード
	mCnum		// 総数
}CS;

// 表示エフェクト文字
enum Moji
{
	mDoxuru,	// ドゥルルル
	mDen,		// デン
	mMoji_All
};

class Graphics
{
public:
	Graphics();
	~Graphics();

	/*** ThisScene ***/
	// ロード処理
	static void LoadMainGraph();
	static void LoadPlayerGraph();
	static void LoadEnemyGraph();
	static void LoadCrystalGraph();
	static void LoadMojiGraph();

	// 取得処理
	static int GetMainGraph(int);
	static int GetPlayerGraph(int);
	static int GetEnemyGraph(int);
	static int GetCrystalGraph(int);
	static int GetMojiGraph(int);
	/*****************/

private:
	/*** static ***/
	static int m_gr[MG::mAll_num];		// mainフォルダ内画像格納変数
	static int p_gr[CS::mCnum];			// playerフォルダ内画像格納変数
	static int e_gr[CS::mCnum];			// enemyフォルダ内画像格納変数
	static int b_gr[6];					// etc/cystalフォルダ内画像格納変数
	static int mo_gr[Moji::mMoji_All];	// mojiフォルダ内画像格納変数
	/**************/
};
typedef Graphics Graph;