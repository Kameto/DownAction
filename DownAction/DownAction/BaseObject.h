/*
�w�Дԍ��Fj17086
���O�F�T�c����
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
		double cx;		// �摜���W
		double cy;		// �摜���W
		double ccx;		// ���������p���W
		double ccy;		// ���������p���W
		double speed;	// �ړ����x
		double gravty;	// �d��
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
		int sizeX;			// �摜�T�C�Y
		int sizeY;			// �摜�T�C�Y
		int state;			// �L�������
		bool activFlag;		// �s���t���O
		bool downFlag;		// �����t���O
		bool dirFlag;		// �����t���O
		bool hitObjFlag;	// ����t���O
		
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
	bool HitObject(BaseObject* bo1);// �����蔻��
	ObjState::ObjPoint* mpPoint;	// ���W�֘A
	ObjState::ObjInfo* mpInfo;		// ���W�ȊO�̂��̑����
};