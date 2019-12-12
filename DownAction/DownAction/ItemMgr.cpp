#include "ItemMgr.h"

const int ItemMgr::possItem;
bool* ItemMgr::possItemFlag = nullptr;
bool ItemMgr::possMaxFlag;

ItemMgr::ItemMgr()
{
	possItemFlag = new bool[possItem];
	for (int i = 0; i < possItem; i++)
	{
		possItemFlag[i] = false;
	}
	possItemFlag[0] = true;
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