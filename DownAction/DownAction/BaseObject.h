/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "Camera.h"
#include "Score.h"
#include "JoyPad.h"

namespace ObjState
{
	class ObjPoint
	{
	public:
		ObjPoint() 
		{
			cx		 = 0.0;
			cy		 = 0.0;
			ccx		 = 0.0;
			ccy		 = 0.0;
			speed	 = 0.0;
			gravty	 = 0.0;
		};
		ObjPoint(int _x, int _y)
		{
			cx = _x;
			cy = _y;
			ccx = 0;
			ccy = 0;
			speed = 0;
			gravty = 0;
		}
		~ObjPoint() 
		{
			cx		 = 0.0;
			cy		 = 0.0;
			ccx		 = 0.0;
			ccy		 = 0.0;
			speed	 = 0.0;
			gravty	 = 0.0;
		};
		double cx;		// 画像座標
		double cy;		// 画像座標
		double ccx;		// 内部処理用座標
		double ccy;		// 内部処理用座標
		double speed;	// 移動速度
		double gravty;	// 重力
	};

	class ObjInfo
	{
	public:
		ObjInfo()
		{
			sizeX		 = 0;
			sizeY		 = 0;
			state		 = 0;
			activFlag	 = false;
			downFlag	 = false;
			dirFlag		 = false;
			hitObjFlag	 = false;
		};
		~ObjInfo()
		{
			sizeX		 = 0;
			sizeY		 = 0;
			state		 = 0;
			activFlag	 = false;
			downFlag	 = false;
			dirFlag		 = false;
			hitObjFlag	 = false;
		};
		int sizeX;			// 画像サイズ
		int sizeY;			// 画像サイズ
		int state;			// キャラ状態
		bool activFlag;		// 行動フラグ
		bool downFlag;		// 落下フラグ
		bool dirFlag;		// 向きフラグ
		bool hitObjFlag;	// 判定フラグ
		
	};
}

class BaseObject
{
public:
	BaseObject() 
	{
		mpPoint = new ObjState::ObjPoint();
		mpInfo = new ObjState::ObjInfo();
	};
	virtual ~BaseObject()
	{
		DEL_OBJ(mpPoint);
		DEL_OBJ(mpInfo);
	};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool HitObject(BaseObject* bo1);// あたり判定
	ObjState::ObjPoint* mpPoint;	// 座標関連
	ObjState::ObjInfo* mpInfo;		// 座標以外のその他情報
};