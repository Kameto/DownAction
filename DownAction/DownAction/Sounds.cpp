/*
学籍番号：j17086
名前：亀田朋来
*/

#include"Sounds.h"

std::vector<int>Sounds::data;

Sounds::Sounds()
{
	data.resize(SoundName::sNum);
	for (int i = 0, n = (unsigned)data.size(); i < n; i++)
	{
		data[i] = 0;
	}
	data[0] = LoadSoundMem("sound/BGM/BGMイントロ.mp3");
	data[1] = LoadSoundMem("sound/BGM/メインBGM.mp3");
	data[2] = LoadSoundMem("sound/BGM/DownBGMイントロ.mp3");
	data[3] = LoadSoundMem("sound/BGM/メインDownBGM.mp3");
	data[4] = LoadSoundMem("sound/SE/ban.wav");
	data[5] = LoadSoundMem("sound/SE/buuum.wav");
	data[6] = LoadSoundMem("sound/SE/piko.wav");
	data[7] = LoadSoundMem("sound/SE/pyun.wav");
}

Sounds::~Sounds()
{
	for (int i = 0, n = (unsigned)data.size(); i < n; i++)
	{
		if (data[i] != 0 || data[i] != -1)
		{
			DeleteSoundMem(data[i]);
		}
		data[i] = 0;
	}
	data.erase(data.begin(), data.end());
}