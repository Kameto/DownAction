#include"Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(double _x, double _y)
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
	// –CŒ‚E”š”­‚­‚ç‚¢‚©‚ÈH‚Ü‚¾l‚¦‚Ä‚¢‚éÅ’†

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