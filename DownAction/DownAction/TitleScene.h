/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#pragma once
#include "BaseScene.h"
#include "Player.h"

class TitleScene
	: public BaseScene
{
public:
	TitleScene(); 
	~TitleScene();
	void Update();
	void Draw();

	int cmtCounter;	// �R�����g�\���p�J�E���^�[
	int sele;		// �I�����Ă��鍀�ڕϐ�
	int modeCount;	// debug���[�h�Ǘ��J�E���g
	bool sceneFlag;	// �t�F�[�h�����p�t���O
	bool startFlag;	// 
	bool cmtFlag;	// �R�����g�\���p�t���O
};