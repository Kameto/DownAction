#include "ItemChangeScene.h"

ItemChangeScene::ItemChangeScene()
{
	nowItem[0] = nowItem[1] = nowItem[2] = NULL;
	for (int i = 0; i < ItemMgr::possItem; i++)
	{
		nowItem[i] = ItemMgr::setItem[i];
	}
	cFlag = false;
	SetDrawBright(255, 255, 255);
}

ItemChangeScene::~ItemChangeScene()
{
	if (cFlag)
	{
		for (int i = 0; i < ItemMgr::possItem; i++)
		{
			ItemMgr::setItem[i] = nowItem[i];
		}
		cFlag = false;
	}
	nowItem[0] = nowItem[1] = nowItem[2] = NULL;	
}

void ItemChangeScene::Update()
{
	this->UI_Update();
}

void ItemChangeScene::Draw()
{
	this->UI_Draw();
}

void ItemChangeScene::UI_Update()
{
	// à⁄ìÆ
	if (Keyboard::GetKey(KEY_INPUT_RIGHT) == 1)
	{

	}
	else if (Keyboard::GetKey(KEY_INPUT_RIGHT) == 1)
	{

	}

	// åàíËÅEâèú
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{

	}
	else if (Keyboard::GetKey(KEY_INPUT_BACK) == 1)
	{

	}
}

void ItemChangeScene::UI_Draw()
{
	DrawRotaGraph(384, 540, 1.30, PI / 2, Graphics::GetMainGraph(MG::mItemBox), false, false);

	for (int i = 0, n = (int)ItemName::mAll; i < n; i++)
	{
		if (ItemMgr::possItemFlag[i] == true)
		{
			DrawRotaGraph(1000, 540, 1.3, 0.0, Graphics::GetMainGraph(MG::mCandela + i), false, false);
		}
		else
		{
			DrawRotaGraph(1000, 540, 1.3, 0.0, Graphics::GetMainGraph(MG::mChain), false, false);
			DrawRotaGraph(1000, 540, 1.3, 0.0, Graphics::GetMainGraph(MG::mKeyLock), false, false);
		}
	}
}