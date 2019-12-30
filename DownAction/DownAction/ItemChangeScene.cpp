#include "ItemChangeScene.h"

ItemChangeScene::ItemChangeScene()
{
	nowItem[0] = nowItem[1] = nowItem[2] = NULL;
	for (int i = 0; i < ItemMgr::possItem; i++)
	{
		nowItem[i] = ItemMgr::setItem[i];
	}
	cFlag = false;
	nHei = nWid = 0;
	changeItem = 0;
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
	nHei = nWid = 0;
	changeItem = 0;
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
#ifdef _DEBUG
	if (Keyboard::GetKey(KEY_INPUT_TAB) == 1)
	{
		cFlag = false;
		BaseScene::nowScene = SceneName::eTitle;
	}
#endif

	// 移動
	if (Keyboard::GetKey(KEY_INPUT_RIGHT) == 1 && this->widR.max > nWid)
	{
		nWid++;
	}
	else if (Keyboard::GetKey(KEY_INPUT_LEFT) == 1 && this->widR.min < nWid)
	{
		nWid--;
	}
	else if (Keyboard::GetKey(KEY_INPUT_UP) == 1 && this->heiR.max > nHei)
	{
		nHei++;
	}
	else if (Keyboard::GetKey(KEY_INPUT_DOWN) == 1 && this->heiR.min < nHei)
	{
		nHei--;
	}

	// 決定・解除
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		if (changeItem < ItemMgr::possItem)
		{
			if (ItemMgr::possItemFlag[nWid + (nHei * (widR.max + 1))] == true
				&& ((int)MG::mCandela + nWid + (nHei * (widR.max + 1))) < (int)MG::mAll_num)
			{
				nowItem[changeItem] = nWid + (nHei * (widR.max + 1));
				changeItem++;
			}
		}
		else
		{
			BaseScene::nowScene = SceneName::eTitle;
		}
	}
	else if (Keyboard::GetKey(KEY_INPUT_BACK) == 1 && changeItem > 0)
	{
		nowItem[changeItem - 1] = -1;
		changeItem--;
	}

	if (changeItem == ItemMgr::possItem)
	{
		cFlag = true;
	}
	else
	{
		cFlag = false;
	}
}

void ItemChangeScene::UI_Draw()
{
	// 背景
	DrawCircle(1920 / 2, 1080 / 2, 800, 0xFFFFFF, true);
	DrawCircle(1920 / 2, 32, 600,0x0000FF, true);
	DrawCircle(320 + 32, 1080, 600,0xFF0000, true);
	DrawCircle(1600 - 32, 1080, 600,0x00FF00, true);

	// 所持アイテムボックス
	DrawRotaGraph(256, 540, 3.0, PI / 2, Graphics::GetMainGraph(MG::mItemBox), false, false);

	// セットアイテム描画
	for (int i = 0; i < ItemMgr::possItem; i++)
	{
		if (nowItem[i] != -1)
		{
			DrawRotaGraph(256, 256 + (i * 288), 0.65, 0.0, Graphics::GetMainGraph(MG::mCandela + nowItem[i]), true, false);
		}
	}

	// 所持アイテム描画
	for (int i = 0, n = widR.max; i <= n; i++)
	{
		DrawBox(600 + (i * 192) - 96, 540 - 96, 600 + (i * 192) + 96, 540 + 96, 0x000000, true);
		DrawBox(600 + (i * 192) - 86, 540 - 86, 600 + (i * 192) + 86, 540 + 86, 0xFFFFFF, true);

		// アイテム数がオーバーフローしていなくて、アイテムを所持していて、画像が存在しているなら
		if ((int)ItemName::mAll > i + (nHei * 5) && ItemMgr::possItemFlag[i + (nHei * n)] == true && ((int)MG::mCandela + i) < (int)MG::mAll_num)
		{
			DrawRotaGraph(600 + (i * 192), 540, 0.45, 0.0, Graphics::GetMainGraph(MG::mCandela + i + (nHei * n) + nHei), true, false);
		}
		else
		{
			DrawRotaGraph(600 + (i * 192), 540, 0.85, 0.0, Graphics::GetMainGraph(MG::mChain), true, false);
			DrawRotaGraph(600 + (i * 192), 540, 0.85, 0.0, Graphics::GetMainGraph(MG::mKeyLock), true, false);
		}
	}

	// アイテム枠
	if (changeItem < ItemMgr::possItem)
	{
		DrawBoxAA(256 - 112, 256 + (changeItem * 288) - 112, 256 + 112, 256 + (changeItem * 288) + 112, 0x00A0FF, false, 10.0f);
	}
	else
	{
		DrawBoxAA(256 - 112, 256 + ((changeItem - 1) * 288) - 112, 256 + 112, 256 + ((changeItem - 1) * 288) + 112, 0x00A0FF, false, 10.0f);
	}
	DrawBoxAA(600 + (nWid * 192) - 96, 540 - 96, 600 + (nWid * 192) + 96, 540 + 96, 0xFF00FF, false, 10.0f);

	// (x1, y1, x2, y2, x3, y3) // (左下、右下、頂点)
	if (this->heiR.max > nHei)
	{
		DrawTriangleAA(tp[0][0] - 96, tp[0][1], tp[0][0] + 96, tp[0][1], tp[0][0], tp[0][1] - 96, 0xFF00FF, true, 10.0f);
		DrawTriangleAA(tp[0][0] - 96, tp[0][1], tp[0][0] + 96, tp[0][1], tp[0][0], tp[0][1] - 96, 0xFFFF00, false, 10.0f);
		DrawExtendFormatString(tp[0][0] + 128, tp[0][1], 1.5, 1.5, 0x000000, "UP Arrow Key");
	}

	if (this->heiR.min < nHei)
	{
		DrawTriangleAA(tp[1][0] - 96, tp[1][1], tp[1][0] + 96, tp[1][1], tp[1][0], tp[1][1] + 96, 0xFF00FF, true, 10.0f);
		DrawTriangleAA(tp[1][0] - 96, tp[1][1], tp[1][0] + 96, tp[1][1], tp[1][0], tp[1][1] + 96, 0xFFFF00, false, 10.0f);
		DrawExtendFormatString(tp[1][0] + 128, tp[1][1], 1.5, 1.5, 0x0000ccc00, "DOWN Arrow Key");
	}

#ifdef _DEBUG
	DrawExtendFormatString(1920 / 2 - 192, 100, 1.0, 1.0, 0xFFFFFF, "back to title => push tab key");
	DrawExtendFormatString(1920 / 2 - 192, 200, 1.0, 1.0, 0xFFFFFF, "nHei : %d\nnWid : %d", nHei, nWid);
	DrawExtendFormatString(1920 / 2 - 192, 300, 1.0, 1.0, 0xFFFFFF, "nowItem[0] : %d nowItem[1] : %d nowItem[2] : %d", nowItem[0], nowItem[1], nowItem[2]);
	DrawExtendFormatString(1920 / 2 - 192, 400, 1.0, 1.0, 0xFFFFFF, cFlag ? "cFlag : true" : "cFlag : false");
#endif
}