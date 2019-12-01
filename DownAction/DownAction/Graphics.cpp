#include "Graphics.h"

int Graphics::m_gr[MG::mAll_num] = { {NULL} };
int Graphics::p_gr[CS::mCnum] = { {NULL} };
int Graphics::e_gr[CS::mCnum] = { {NULL} };
int Graphics::b_gr[6] = { {NULL} };

Graphics::Graphics()
{
	for (int i = 0, n = MG::mAll_num; i < n; i++)
	{
		m_gr[i] = 0;
	}
	for (int i = 0, n = CS::mCnum; i < n ; i++)
	{
		p_gr[i] = 0;
		e_gr[i] = 0;
	}
	LoadMainGraph();
	LoadPlayerGraph();
	LoadEnemyGraph();
	LoadCrystalGraph();
}

Graphics::~Graphics()
{
	for (int i = 0, n = MG::mAll_num; i < n; i++)
	{
		DeleteGraph(m_gr[i]);
		m_gr[i] = 0;
	}
	for (int i = 0, n = CS::mCnum; i < n; i++)
	{
		DeleteGraph(p_gr[i]);
		p_gr[i] = 0;
		DeleteGraph(e_gr[i]);
		e_gr[i] = 0;
	}
	for (int i = 0, n = 6; i < n; i++)
	{
		DeleteGraph(b_gr[i]);
		b_gr[i] = 0;
	}
}

void Graphics::LoadMainGraph()
{
	std::string path = "";
	for (int i = 0, n = MG::mAll_num, _gr = 0; i < n; i++)
	{
		path = "graph/main/" + std::to_string(i) +".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			m_gr[i] = _gr;
		}
	}
}

void Graphics::LoadPlayerGraph()
{
	std::string path = "";
	for (int i = 0, n = CS::mCnum, _gr = 0; i < n; i++)
	{
		path = "graph/player/" + std::to_string(i) + ".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			p_gr[i] = _gr;
		}
	}
}

void Graphics::LoadEnemyGraph()
{
	std::string path = "";
	for (int i = 0, n = CS::mCnum, _gr = 0; i < n; i++)
	{
		path = "graph/enemy/" + std::to_string(i) + ".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			e_gr[i] = _gr;
		}
	}
}

void Graphics::LoadCrystalGraph()
{
	std::string path = "";
	for (int i = 0, n = 6, _gr = 0; i < n; i++)
	{
		path = "graph/etc/crystal/" + std::to_string(i) + ".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			b_gr[i] = _gr;
		}
	}
}

int Graphics::GetMainGraph(int _num)
{
	return m_gr[_num];
}

int Graphics::GetPlayerGraph(int _state)
{
	return p_gr[_state];
}

int Graphics::GetEnemyGraph(int _state)
{
	return e_gr[_state];
}

int Graphics::GetCrystalGraph(int _num)
{
	return b_gr[_num];
}