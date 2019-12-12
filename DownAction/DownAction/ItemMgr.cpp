#include "ItemMgr.h"

const int ItemMgr::possItem;
bool* ItemMgr::possItemFlag = nullptr;
bool ItemMgr::possMaxFlag;

ItemMgr::ItemMgr()
{
	possItemFlag = new bool[possItem];
	possItemFlag[0] = true;
	for (int i = 1; i < possItem; i++)
	{
		possItemFlag[i] = false;
	}
	possMaxFlag = false;
}

ItemMgr::~ItemMgr()
{
	delete[] possItemFlag;
	possMaxFlag = false;
}

bool ItemMgr::CheckItem()
{
	for (int i = 0; i < possItem; i++)
	{
		if (possItemFlag[i] == false)
		{
			break;
		}

		if (i == possItem - 1 && possItemFlag[i] == true)
		{
			return true;
		}
	}
	return false;
}