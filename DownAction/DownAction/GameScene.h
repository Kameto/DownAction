/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#pragma once
#include <cmath>
#include <vector>
#include "BaseScene.h"
#include "Block.h"
#include "Camera.h"
#include "DataFile.h"
#include "Enemy.h"
#include "Font.h"
#include "Item.h"
#include "Player.h"
#include "TimeWatch.h"

#define PI 3.14159265359
#define TRANS_SX 1800
#define TRANS_SY 960

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
	TimeWatch* tw;
	std::vector<Block*>block;
	std::vector<Item*>item;
	std::vector<Enemy*>enemy;

	// �M�~�b�N�֌W
	double stickX;
	double stickY;
	double radian;
	int range;

	int counter[4];
	int goalPoint;	// �S�[�����W
	bool goalFlag;	// �Q�[���N���A�t���t
	bool overFlag;	// �Q�[���I�[�o�[�t���O
	bool explanFlag;// �����t���O
	bool tEndFlag;	// �����I���t���O
	bool getFlag;	// �A�C�e���擾�t���O
	bool brightFlag;// ���ʃt���O
};