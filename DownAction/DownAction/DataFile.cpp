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
	// �{���Ȃ�t�@�C������ǂ݂��܂���\�肾���ǁA
	// ����m�F�̂��߈ꎞ�I�ɒ��ڏ�������ł���B

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

	text.push_back("�͂��߂܂��āB�����Ȃ�ł����Q�[���̐��������܂��ˁB\n�܂��L�[�{�[�h�Ȃ�A�L�[��D�L�[�ō��E�̈ړ����ł��܂��B\nXbox�R���g���[���[�Ȃ�\���L�[�̍��E�ňړ����ł��܂��B");
	text.push_back("���ɃL�����N�^�[�̕ϐg�M�~�b�N�ł��B\n�L�[�{�[�h�Ȃ���L�[���g���A���E�ŃX�e�B�b�N���񂵁A\n��L�[�őI���BSpace�L�[�ŕϐg���܂��B");
	text.push_back("Xbox�R���g���[���[�Ȃ�E�X�e�b�N�𑀍삵�āA\nL2�g���K�[�ŕϐg���܂��B");
	text.push_back("���̃Q�[���̓X�R�A�ƃ^�C���A�^�b�N�����тƂ��Ĕ��f����܂��B\n�o���邾�������̃A�C�e��������đ����S�[�����܂��傤!\n����ł̓X�^�[�g�ł��I");
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