#include "ItemMgr.h"

const int ItemMgr::possItem;
bool* ItemMgr::possItemFlag = nullptr;
bool ItemMgr::possMaxFlag;
int* ItemMgr::setItem = nullptr;

ItemMgr::ItemMgr()
{
	possItemFlag = new bool[(int)ItemName::mAll];
	for (int i = 0; i < (int)ItemName::mAll; i++)
	{
		possItemFlag[i] = false;
	}
	setItem = new int[possItem];
	for (int i = 0; i < possItem; i++)
	{
		setItem[i] = 999;
	}
	setItem[0] = (int)ItemName::IN_mCandela;
	setItem[1] = (int)ItemName::IN_mCrystal;
	setItem[2] = (int)ItemName::IN_mMap;
	possItemFlag[setItem[0]] = true;
	possItemFlag[setItem[1]] = true;
	possItemFlag[setItem[2]] = true;
	possMaxFlag = false;
}

ItemMgr::~ItemMgr()
{
	delete[] possItemFlag;
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