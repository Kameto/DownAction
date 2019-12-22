#include "DataFile.h"

std::vector<Point>DataFile::objP;
std::vector<std::string>DataFile::time;
std::vector<int>DataFile::score;
std::vector<std::string>DataFile::text;

DataFile::DataFile()
{
	objP.resize(0);
	score.resize(0);
	time.resize(0);
	text.resize(0);
}

DataFile::~DataFile()
{
	WriteData();
	if (!objP.empty())
	{
		objP.erase(objP.begin(), objP.end());
	}
	if (!score.empty())
	{
		score.erase(score.begin(), score.end());
	}
	if (!time.empty())
	{
		time.erase(time.begin(), time.end());
	}
	if (!text.empty())
	{
		text.erase(text.begin(), text.end());
	}
}

int DataFile::Load(std::string path)
{
	std::ifstream ifs;
	std::string str, token;
	
	ifs.open(path);
	if (!ifs.fail()) 
	{
		while (getline(ifs,str))
		{
			std::istringstream iss(str);
			std::string gstr[2];
			Point p;
			int c = 0;
			while (getline(iss, token, ','))
			{
				gstr[c] = token;
				c++;
			}
			p.x = stoi(gstr[1]);
			p.y = stoi(gstr[0]);
			objP.push_back(p);
		}
	}
	else
	{
		return -1;
	}

	return 0;
}

void DataFile::Clear()
{
	objP.erase(objP.begin(), objP.end());
	objP.resize(0);
}

int DataFile::LoadText()
{
	// 2019-11-21-Thurs
	// 本来ならファイルから読みこませる予定だけど、
	// 動作確認のため一時的に直接書き込んでいる。

	/*
	std::ifstream ifs;
	std::string str;
	ifs.open("datafile/textdata.csv");
	if (!ifs.fail())
	{
		while (getline(ifs, str))
		{
			text.push_back(str);
		}
	}
	else
	{
		return -1;
	}
	return 0;
	*/

	text.push_back("はじめまして。いきなりですがゲームの説明をしますね。\nまずキーボードならAキーとDキーで左右の移動ができます。\nXboxコントローラーなら十字キーの左右で移動ができます。");
	text.push_back("次にキャラクターの変身ギミックです。\nキーボードなら矢印キーを使い、左右でスティックを回し、\n上キーで選択。Spaceキーで変身します。");
	text.push_back("Xboxコントローラーなら右ステックを操作して、\nL2トリガーで変身します。");
	text.push_back("このゲームはスコアとタイムアタックが成績として反映されます。\n出来るだけ多くのアイテムを取って早くゴールしましょう!\nそれではスタートです！");
	return 0;
}

void DataFile::WriteData()
{
	std::ofstream ofs;
	ofs.open("datafile/scorefile/scoredata.csv", std::ios::app);
	if (!ofs.fail())
	{
		std::string str = "";
		if (!score.empty())
		{
			for (int i = 0, n = (unsigned)score.size(); i < n; i++)
			{
				str = std::to_string(score.at(i)) + "," + time.at(i) + "\n";
				ofs << str;
			}
		}
	}
	ofs.close();
}