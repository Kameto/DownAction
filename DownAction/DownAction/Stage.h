/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "DefaultFunc.h"

class Stage
{
public:
	Stage();
	~Stage();
	void FileLoad();

	static std::vector<std::vector<int>>data;
	static int dataCount;
};