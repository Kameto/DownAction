#include "Block.h"

Block::Block()
	: BaseObject()
{
	mpInfo->sizeX = 64;
	mpInfo->sizeY = 16;
	mpInfo->activFlag = false;
}

Block::Block(double _x, double _y)
	: BaseObject()
{
	mpPoint->cx = _x;
	mpPoint->cy = _y;
	GetGraphSize(Graphics::GetMainGraph(MG::mBlock), &mpInfo->sizeX, &mpInfo->sizeY);
	mpInfo->activFlag = true;
}

Block::~Block()
{
	
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

	DrawRotaGraph(mpPoint->cx, mpPoint->cy - Camera::my, 1.0, 0.0, Graphics::GetMainGraph(MG::mBlock), false, false);
}