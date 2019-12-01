#pragma once
#include "GameScene.h"		// GameScene,Graphics,Keyboard,DataFile,Score
#include "ResultScene.h"	// ResulScene,Graphics,Keyboard,DataFile,Score
#include "TitleScene.h"		// TitleScene,Graphics,Keyboard

class SceneMgr
{
public:
	SceneMgr(); 
	~SceneMgr();

 	void ChangeScene();
	void SceneUpdate();
	void SceneDraw();
	bool GetEndFlag();

private:
	BaseScene* mpScene;	// �V�[���p�|�C���^�[
	SceneName preScene;	// �O�V�[���L�������o
	Graphics* gra;		// �摜�N���X�|�C���^�[
	DataFile* df;		// �t�@�C���֘A�N���X�|�C���^�[
	Score* sc;			// �Q�[�����X�R�A�N���X�|�C���^�[
};