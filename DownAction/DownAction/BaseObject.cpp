/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#include"BaseObject.h"

bool BaseObject::HitObject(BaseObject* bo1)
{
	int Xrange = abs((int)this->mpPoint->cx - (int)bo1->mpPoint->cx);	// �I�u�W�F�N�g�Ԃ�X���W������Βl

	double a = this->mpPoint->cy + this->mpPoint->gravty + Camera::my;
	double b = bo1->mpPoint->cy;

	int Yrange = (int)abs(a - b);	// �I�u�W�F�N�g�Ԃ�Y���W������Βl
	int XSrange = (int)(this->mpInfo->sizeX + bo1->mpInfo->sizeX) / 2;		// �I�u�W�F�N�g�̉��T�C�Y�a�l
	int YSrange = (int)(this->mpInfo->sizeY + bo1->mpInfo->sizeY) / 2;		// �I�u�W�F�N�g�̏c�T�C�Y�a�l

	if (Xrange < XSrange && Yrange < YSrange)
	{
		return true;
	}
	else
	{
		return false;
	}
}