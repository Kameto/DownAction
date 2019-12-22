#include"Item.h"

Item::Item()
	: BaseObject()
{
	this->mpPoint->cx = 128;
	this->mpPoint->cx = 128;
	this->mpInfo->sizeX = 16;
	this->mpInfo->sizeY = 16;
	this->mpInfo->activFlag = true;
}

Item::Item(double _x, double _y)
	: BaseObject()
{
	this->mpPoint->cx = _x;
	this->mpPoint->cy = _y;
	this->mpInfo->sizeX = 32;
	this->mpInfo->sizeY = 32;
	this->mpInfo->activFlag = true;
}

Item::~Item()
{
}

void Item::Update()
{
	
}

void Item::Draw()
{
	if (this->mpInfo->activFlag)
	{
		/*
		DrawBox(mpPoint->cx - (mpInfo->sizeX / 2), mpPoint->cy - (mpInfo->sizeY / 2),
				mpPoint->cx + (mpInfo->sizeX / 2), mpPoint->cy + (mpInfo->sizeY / 2),
										 0xFF00FF,								true);
		*/

		DrawRotaGraph(mpPoint->cx, mpPoint->cy - Camera::my, 0.5, 0.0, Graph::GetMainGraph(MG::mItem), true, false);
	}
}