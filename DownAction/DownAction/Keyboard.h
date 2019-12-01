#pragma once
#include "DxLib.h"
#include "DefaultFunc.h"

class Keyboard
{
public:
	Keyboard(); 
	~Keyboard();
	static void KeyUpdate();
	static void Reset(int keycode);
	static int GetKey(int keycode);

private:
	static int key[256];
	static char tmpkey[256];
};