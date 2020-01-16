/*
学籍番号：j17086
名前：亀田朋来
*/

#include"BaseObject.h"

bool BaseObject::HitObject(BaseObject* bo1)
{
	int Xrange = abs((int)this->mpPoint->cx - (int)bo1->mpPoint->cx);	// オブジェクト間のX座標総差絶対値

	double a = this->mpPoint->cy + this->mpPoint->gravty + Camera::my;
	double b = bo1->mpPoint->cy;

	int Yrange = (int)abs(a - b);	// オブジェクト間のY座標総差絶対値
	int XSrange = (int)(this->mpInfo->sizeX + bo1->mpInfo->sizeX) / 2;		// オブジェクトの横サイズ和値
	int YSrange = (int)(this->mpInfo->sizeY + bo1->mpInfo->sizeY) / 2;		// オブジェクトの縦サイズ和値

	if (Xrange < XSrange && Yrange < YSrange)
	{
		return true;
	}
	else
	{
		return false;
	}
}