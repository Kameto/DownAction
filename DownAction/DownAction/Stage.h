/*
�w�Дԍ��Fj17086
���O�F�T�c����
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