#pragma once
#include "DxLib.h"
#include <vector>

enum SoundName
{
	sIntoGRM,
	sBGM,
	sIntoD_GRM,
	sD_BGM,
	sAttackSE,
	sLongAtkSE,
	sSelectSE,
	sDeleteSE,
	sNum
};

class Sounds
{
public:
	Sounds(); 
	~Sounds();

	static std::vector<int>data;
};