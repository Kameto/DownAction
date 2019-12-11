#include"Player.h"

int Player::enegy;

Player::Player()
	: BaseObject()
{
	mpPoint->cx		 = 600.0;
	mpPoint->cy		 = 0.0;
	mpPoint->ccx	 = mpPoint->cx;
	mpPoint->ccy	 = mpPoint->cy;
	mpPoint->speed	 = DEFAULT_SPD;
	mpPoint->gravty	 = DEFAULT_GRV;
	mpInfo->sizeX	 = 64;
	mpInfo->sizeY	 = 64;
	mpInfo->dirFlag = false;
	mpInfo->downFlag = true;
	enegy			 = 0;
	life			 = 4;
	counter[0]		 = 0;
	counter[1]		 = 0;
	counter[2]		 = 0;
	counter[3]		 = 0;
	bCount			 = 3;
	actionFlag		 = false;
	damegeFlag		 = false;
	fuwaFlag		 = false;
	kataFlag		 = false;
	blockFlag		 = false;
	dir = Dir::mNone;
}

Player::~Player()
{
	enegy		 = 0;
	life		 = 0;
	counter[0]	 = 0;
	counter[1]	 = 0;
	counter[2]	 = 0;
	counter[3]	 = 0;
	bCount		 = 0;
	actionFlag	 = false;
	damegeFlag	 = false;
	fuwaFlag	 = false;
	kataFlag	 = false;
	blockFlag	 = false;
	dir			 = Dir::mNone;
}

void Player::StateUpdate()
{
	// プレイヤー状態変化
	// 落下しているかどうか
	if (mpInfo->downFlag == true)
	{
		mpInfo->state = CS::mDown;
	}
	else
	{
		mpInfo->state = CS::mNomal;
	}

	//	左右どちらを向いているか
	if (dir == Dir::mRight)
	{
		mpInfo->dirFlag = true;
	}
	else if (dir == Dir::mLeft)
	{
		mpInfo->dirFlag = false;
	}

	// 変身しているかどうか
	if (fuwaFlag == true || kataFlag == true)
	{
		counter[0]++;
		if (counter[0] % 64 == 0)
		{
			enegy--;
		}
		if (enegy == 0)
		{
			counter[0] = 0;
			fuwaFlag = kataFlag = false;
			mpPoint->speed = DEFAULT_SPD;
		}
	}

	// 変化（かるいとき）時処理
	if (fuwaFlag == true)
	{
		this->mpPoint->gravty = 2;
		mpPoint->speed = DEFAULT_SPD + 6;
		this->mpInfo->state = CS::mFuwafuwa;
	}
	else {}

	// 変化（かたいとき）時処理
	if (kataFlag == true)
	{
		this->mpPoint->gravty = 24;
		mpPoint->speed = DEFAULT_SPD - 4;
		this->mpInfo->state = CS::mKatai;
	}
	else {}

	// ダメージを受けているとき
	if (damegeFlag == true)
	{
		mpInfo->state = CS::mDamage;
		counter[2]++;
		if (counter[2] == 120)
		{
			damegeFlag = false;
			counter[2] = 0;
			mpInfo->state = CS::mNomal;
		}
	}

	// ブロック透過用処理
	if (bCount != 0 && blockFlag == false && Keyboard::GetKey(KEY_INPUT_C) == 1)
	{
		blockFlag = true;
		counter[3] = 0;
	}

	if (blockFlag == true)
	{
		if (counter[3] < 120)
		{
			counter[3]++;
		}
		else
		{
			blockFlag = false;
			bCount--;
			bCount--;
		}
	}
}

void Player::Update()
{
	mpPoint->ccx = mpPoint->cx;

	// 重力落下 //
	if (mpInfo->downFlag && mpPoint->cy + Camera::my < (STAGE_HIEGHT * 32.0))
	{
		if (mpPoint->cy <= (WIND_HEIGHT / 2))
		{
			mpPoint->cy += mpPoint->gravty;
			mpPoint->ccy = mpPoint->cy;
		}
		else
		{
			mpPoint->ccy += mpPoint->gravty;
		}
		mpPoint->gravty += 0.1;
	}
	else
	{
		if (mpPoint->gravty > DEFAULT_GRV)
		{
			mpPoint->gravty = DEFAULT_GRV;
		}
	}

	// 左右移動 //
	if (Keyboard::GetKey(KEY_INPUT_D) > 0 && mpPoint->cx + (mpInfo->sizeX / 2) + mpPoint->speed < (1920 - (double)WALL_WIDTH))
	{
		dir = Dir::mRight;
	}
	else if (Keyboard::GetKey(KEY_INPUT_A) > 0 && mpPoint->cx - (mpInfo->sizeX / 2) - mpPoint->speed > WALL_WIDTH)
	{
		dir = Dir::mLeft;
	}
	else
	{
		dir = Dir::mNone;
	}

	switch (dir)
	{
	case Dir::mRight:
		mpPoint->cx += mpPoint->speed;
		break;
	case Dir::mLeft:
		mpPoint->cx -= mpPoint->speed;
		break;
	case Dir::mNone:
		break;
	default:
		break;
	}

	this->StateUpdate();
}

void Player::Draw()
{
#ifdef _DEBUG
	// プレイヤーカッカリ
	DrawBox(mpPoint->cx - (mpInfo->sizeX / 2), mpPoint->cy - (mpInfo->sizeY / 2),
			mpPoint->cx + (mpInfo->sizeX / 2), mpPoint->cy + (mpInfo->sizeY / 2),
									 0xFF0000,								true);
#endif

	DrawRotaGraph(96, 640, 1.25, PI / 2, Graphics::GetMainGraph(MG::mItemBox), false, false);

	if (damegeFlag == true)
	{
		if (counter[2] <= 10)
		{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
			DrawBox(0, 0, 1920, 1080, 0xFF0000, true);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}

		if (counter[2] % 11 == 0)
		{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
			DrawRotaGraph(mpPoint->cx, mpPoint->cy, 1.0, 0.0, Graph::GetPlayerGraph(mpInfo->state), true, this->mpInfo->dirFlag);
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		}
	}
	else
	{
		DrawRotaGraph(mpPoint->cx, mpPoint->cy, 1.0, 0.0, Graph::GetPlayerGraph(mpInfo->state), true, this->mpInfo->dirFlag);
	}
}