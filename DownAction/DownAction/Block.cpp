/*
学籍番号：j17086
名前：亀田朋来
*/

#include "Block.h"

Block::Block()
	: BaseObject()
{
	mpInfo->sizeX = 64;
	mpInfo->sizeY = 16;
	mpInfo->activFlag = false;
	transFlag = false;
}

Block::Block(double _x, double _y)
	: BaseObject()
{
	mpPoint->cx = _x;
	mpPoint->cy = _y;
	GetGraphSize(Graphics::GetMainGraph(MG::mBlock), &mpInfo->sizeX, &mpInfo->sizeY);
	mpInfo->activFlag = true;
	transFlag = false;
}

Block::~Block()
{
	transFlag = false;
}

void Block::Update()
{
}

void Block::Draw()
{
	// テスト用ブロック
	/*
	DrawBox(mpPoint->cx - (mpInfo->sizeX / 2), mpPoint->cy - (mpInfo->sizeY / 2) - Camera::my,
			mpPoint->cx + (mpInfo->sizeX / 2), mpPoint->cy + (mpInfo->sizeY / 2) - Camera::my,
									 0x00FF00,								true);
	DrawBox(mpPoint->cx - (mpInfo->sizeX / 2), mpPoint->cy - (mpInfo->sizeY / 2) - Camera::my,
			mpPoint->cx + (mpInfo->sizeX / 2), mpPoint->cy + (mpInfo->sizeY / 2) - Camera::my,
									 0xFF0000,								false);
	*/

	if (transFlag == true)
	{
		DrawBox((int)(mpPoint->cx - (mpInfo->sizeX / 2)), (int)(mpPoint->cy - (mpInfo->sizeY / 2) - Camera::my),
			(int)(mpPoint->cx + (mpInfo->sizeX / 2)), (int)(mpPoint->cy + (mpInfo->sizeY / 2) - Camera::my),
			0xFF0000, false);
	}
	else
	{
		DrawRotaGraph((int)mpPoint->cx, (int)(mpPoint->cy - Camera::my), 1.0, 0.0, Graphics::GetMainGraph(MG::mBlock), false, false);
	}
}