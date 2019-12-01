#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
struct Point
{
	int x = 0;
	int y = 0;
};

class DataFile
{
public:
	DataFile();
	~DataFile();
	static int Load(std::string path);
	static void Clear();
	static int LoadText();
	static void WriteData();
	static std::vector<Point>objP;
	static std::vector<int>score;
	static std::vector<std::string>time;
	static std::vector<std::string>text;
};