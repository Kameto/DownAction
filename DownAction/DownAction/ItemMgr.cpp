/*
学籍番号：j17086
名前：亀田朋来
*/

#include "ItemMgr.h"

const int ItemMgr::possItem;
bool* ItemMgr::possItemFlag = nullptr;
bool ItemMgr::possMaxFlag;
int* ItemMgr::setItem = nullptr;

ItemMgr::ItemMgr()
{
	possItemFlag = new bool[(int)ItemName::mAll];
#ifdef _DEBUG
	for (int i = 0; i < (int)ItemName::mAll; i++)
	{
		possItemFlag[i] = true;
	}
	setItem = new int[possItem];
	for (int i = 0; i < possItem; i++)
	{
		setItem[i] = -1;
	}
#else
	for (int i = 0; i < (int)ItemName::mAll; i++)
	{
		possItemFlag[i] = false;
	}
	setItem = new int[possItem];
	for (int i = 0; i < possItem; i++)
	{
		setItem[i] = -1;
	}
#endif
	possMaxFlag = false;
}

ItemMgr::~ItemMgr()
{
	delete[] possItemFlag;
	delete[] setItem;
	possMaxFlag = false;
}

bool ItemMgr::CheckItem()
{
	for (int i = 0, n = (int)ItemName::mAll; i < n; i++)
	{
		if (possItemFlag[i] == false)
		{
			break;
		}

		if (i == n - 1 && possItemFlag[i] == true)
		{
			return true;
		}
	}
	return false;
}

void ItemMgr::DebugMode()
{
	for (int i = 0; i < (int)ItemName::mAll; i++)
	{
		possItemFlag[i] = true;
	}
}