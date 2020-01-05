/*
�w�Дԍ��Fj17086
���O�F�T�c����
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

	/****�@static�@****/
	static int enegy;	// �ϐg�G�i�W�[
	/******************/
	
	/****�@ local�@****/
	Dir dir;			// ����
	int life;			// �̗�
	int counter[4];		// �J�E���^�[
	int bCount;			// �u���b�N���߃J�E���g
	int wCount;			// ���[�v�񐔃J�E���g
	bool actionFlag;	// 
	bool damegeFlag;	// ��e�t���O
	bool fuwaFlag;		// �ϐg�t���O
	bool kataFlag;		// �ϐg�t���O
	bool blockFlag;		// ���߂��Ă��邩���ʃt���O
	/******************/
};