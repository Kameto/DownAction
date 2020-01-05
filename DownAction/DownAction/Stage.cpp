/*
学籍番号：j17086
名前：亀田朋来
*/

#include "Stage.h"
std::vector<std::vector<int>>Stage::data;
int Stage::dataCount;

Stage::Stage()
{
	data.resize(STAGE_HIEGHT);
	for (int i = 0, n = (unsigned)data.size(); i < n; i++)
	{
		data[i].resize(STAGE_WIDTH);
	}
	dataCount = 0;
	FileLoad();
}

Stage::~Stage()
{
	for (int i = 0, n = (unsigned)data.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)data[i].size(); j < m; j++)
		{
			data[i][j] = 0;
		}
	}
	data.erase(data.begin(), data.end());
}

void Stage::FileLoad()
{
	std::ifstream ifs;
	std::string str, token;
	int x = 0, y = 0;
	ifs.open("csv/map.csv");
	if (!ifs.fail())
	{
		while (getline(ifs, str))
		{
			x = 0;
			std::istringstream iss(str);
			while (getline(iss, token, ','))
			{
				data[y][x] = 0;
				data[y][x] = stoi(token);
				if (data[y][x] == 1)
				{
					dataCount++;
				}
				x++;
			}
			y++;
		}
	}
	ifs.close();
}