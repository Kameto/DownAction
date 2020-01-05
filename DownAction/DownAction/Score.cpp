/*
学籍番号：j17086
名前：亀田朋来
*/

#include "Score.h"

int Score::score;

Score::Score()
{
	score = 0;
}

Score::~Score()
{
	score = 0;
}

void Score::ScoreReset()
{
	score = 0;
}