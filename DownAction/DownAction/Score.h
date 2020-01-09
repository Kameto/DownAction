/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
class Score
{
public:
	Score();
	~Score();
	static void ScoreReset();
	static void AddScore();

	static int score;
	static int sum_Score;
};