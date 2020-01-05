/*
学籍番号：j17086
名前：亀田朋来
*/

#include"Enemy.h"

Enemy::Enemy()
	: BaseObject()
{
}

Enemy::Enemy(double _x, double _y)
	: BaseObject()
{
	mpPoint->cx = _x;
	mpPoint->cy = _y;
	mpInfo->sizeX = 32;
	mpInfo->sizeY = 32;
	mpPoint->speed = 4;
	mpInfo->dirFlag = false;
	mpInfo->state = CS::mNomal;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	// 砲撃・爆発くらいかな？まだ考えている最中

	if (mpInfo->activFlag == true)
	{
		if (mpInfo->dirFlag == true)
		{
			mpPoint->cx += mpPoint->speed;
		}
		else
		{
			mpPoint->cx -= mpPoint->speed;
		}
	}
}

void Enemy::Draw()
{
	/*
	DrawBox(mpPoint->cx - (mpInfo->sizeX / 2), mpPoint->cy - (mpInfo->sizeY / 2) - Camera::my,
			mpPoint->cx + (mpInfo->sizeX / 2), mpPoint->cy + (mpInfo->sizeY / 2) - Camera::my,
									 0xFF0000,								true);
	*/
	DrawRotaGraph(mpPoint->cx, mpPoint->cy - Camera::my, 0.35, 0.0, Graph::GetEnemyGraph(mpInfo->state), true, mpInfo->dirFlag);
}