/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#pragma once
#include <filesystem>
#include <tchar.h>
#include <process.h>
#include "Keyboard.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "JoyPad.h"

using namespace std;
namespace fs = filesystem;

enum class SceneName
{
	eTitle,		// �^�C�g��
	eIC_Scene,	// �A�C�e���ύX
	eGame,		// �Q�[��
	eResult,	// ���U���g
	eResult2	// �r�����U���g
};

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	SceneName GetNowScene();
	void EndInput();
	static bool endFlag;

protected:
	void FadeOut(SceneName);
	void FadeIn();
	static SceneName nowScene;
	static bool firstFlag;
	static int counter;
	static int nowStage;
	static int stageNum;
};