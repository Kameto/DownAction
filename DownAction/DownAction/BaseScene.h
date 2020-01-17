/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#pragma once
#include <filesystem>
#include <tchar.h>
#include <process.h>
#include "Graphics.h"
#include "ItemMgr.h"
#include "JoyPad.h"
#include "Keyboard.h"

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
	SceneName GetNowScene();	// ���݃V�[���̎擾
	void EndInput();			// �I���R�}���h�֐�
	static bool endFlag;		// �I���t���O

protected:
	void FadeOut(SceneName);	// �t�F�[�h�C���֐�
	void FadeIn();				// �t�F�[�h�A�E�g�֐�
	static SceneName nowScene;	// ���݃V�[��
	static bool firstFlag;		// ����N���t���O
	static bool modeFlag;		// debug���[�h�t���O
	static int counter;			// ��ʑJ�ڎ��Ɏg�p����J�E���^�[
	static int nowStage;		// �Q�[�����̃X�e�[�W�J�E���g
	static int stageNum;		// �Q�[�����̍ő�X�e�[�W��
};