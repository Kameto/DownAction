/*
学籍番号：j17086
名前：亀田朋来
*/

#include "Score.h"

int Score::score;
int Score::sum_Score;

Score::Score()
{
	score = 0;
	sum_Score = 0;
}

Score::~Score()
{
	score = 0;
	sum_Score = 0;
}

void Score::ScoreReset()
{
	score = 0;
}

void Score::AddScore()
{
	sum_Score += score;
}