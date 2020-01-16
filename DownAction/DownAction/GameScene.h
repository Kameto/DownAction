/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <cmath>
#include <vector>
#include "BaseScene.h"
#include "Block.h"
#include "Camera.h"
#include "DataFile.h"
#include "DefaultFunc.h"
#include "Enemy.h"
#include "Font.h"
#include "Item.h"
#include "Player.h"
#include "TimeWatch.h"

class GameScene
	: public BaseScene
{
public:
	GameScene(); 
	~GameScene();
	void GimmickUpdate();
	void PlayerUpdate();
	void EnemyUpdate();
	void BlockUpdate();
	void ItemUpdate();
	void Update();
	void StageDraw();
	void Draw();

private:
	void StageCreate(const std::string path[]);
	void StageRelease();

	Player* p1;
	Camera* cmr;
	Font* font;
	std::vector<Block*>block;
	std::vector<Item*>item;
	std::vector<Enemy*>enemy;

	// ギミック関係
	double stickX;
	double stickY;
	double radian;
	int range;

	int counter[4];
	int goalPoint;	// ゴール座標
	bool goalFlag;	// ゲームクリアフラフ
	bool overFlag;	// ゲームオーバーフラグ
	bool explanFlag;// 説明フラグ
	bool tEndFlag;	// 説明終了フラグ
	bool getFlag;	// アイテム取得フラグ
	bool brightFlag;// 光量フラグ
};