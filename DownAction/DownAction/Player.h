/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "BaseObject.h"
#include "ItemMgr.h"
#include "JoyPad.h"

typedef enum class Direction
{
	mRight, mLeft, mNone
}Dir;

class Player
	: public BaseObject
{
public:
	Player(); 
	~Player();
	void Update();
	void Draw();
	void StateUpdate();

	/****　static　****/
	static int enegy;	// 変身エナジー
	/******************/
	
	/****　 local　****/
	Dir dir;			// 向き
	int life;			// 体力
	int counter[4];		// カウンター
	int bCount;			// ブロック透過カウント
	int wCount;			// ワープ回数カウント
	bool actionFlag;	// 
	bool damegeFlag;	// 被弾フラグ
	bool fuwaFlag;		// 変身フラグ
	bool kataFlag;		// 変身フラグ
	bool blockFlag;		// 透過しているか判別フラグ
	/******************/
};