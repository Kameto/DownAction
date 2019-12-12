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
		double cx;
		double cy;
		double ccx;
		double ccy;
		double speed;
		double gravty;
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
		int sizeX;
		int sizeY;
		int state;
		bool activFlag;
		bool downFlag;
		bool dirFlag;
		bool hitObjFlag;
		
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
	bool HitObject(BaseObject* bo1);
	ObjState::ObjPoint* mpPoint;
	ObjState::ObjInfo* mpInfo;
};