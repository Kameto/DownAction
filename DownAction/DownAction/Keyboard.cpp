#include"Keyboard.h"

int Keyboard::key[256];
char Keyboard::tmpkey[256];

Keyboard::Keyboard()
{
	for (int i = 0, n = 256; i < n; i++)
	{
		key[i] = 0;
		tmpkey[i] = 0;
	}
}

Keyboard::~Keyboard()
{
	for (int i = 0, n = 256; i < n; i++)
	{
		key[i] = 0;
		tmpkey[i] = 0;
	}
}

void Keyboard::KeyUpdate()
{
	GetHitKeyStateAll(tmpkey);
	for (int i = 0, n = 256; i < n; i++)
	{
		if (tmpkey[i] > 0)
		{
			key[i]++;
		}
		else if (key[i] > 0)
		{
			key[i] = -1;
		}
		else
		{
			key[i] = 0;
		}
	}
}

void Keyboard::Reset(int keycode)
{
	key[keycode] = 0;
}

int Keyboard::GetKey(int keycode)
{
	return key[keycode];
}