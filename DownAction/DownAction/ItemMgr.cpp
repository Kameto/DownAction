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
		possItemFlag[i] = true;
	}
	setItem = new int[possItem];
	for (int i = 0; i < possItem; i++)
	{
		setItem[i] = -1;
	}
#ifdef _DEBUG
	setItem[0] = (int)ItemName::IN_mMask;
	setItem[1] = (int)ItemName::IN_mPortal;
	setItem[2] = (int)ItemName::IN_mMap;
#else
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