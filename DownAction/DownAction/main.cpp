/*
�w�Дԍ��Fj17086
���O�F�T�c����
*/

#include <DxLib.h>
#include "SceneMgr.h"
#include "FPS.hpp"
#include "MyRand.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("DownAction");			// �A�v���P�[�V������

	SetOutApplicationLogValidFlag(false);		// log�t�@�C���̐���
#ifdef _DEBUG
	ChangeWindowMode(true);						// �X�N���[���ݒ�
#else
	ChangeWindowMode(false);					// �X�N���[���ݒ�
#endif
	SetGraphMode(1920, 1080, 32);				// �`��͈�
	SetFontSize(16);							// �����T�C�Y�ݒ�
	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}
	SetMouseDispFlag(false);					// �E�B���h�E���[�h�ł��}�E�X�J�[�\�����\���ɂ���

	Keyboard* key	 = new Keyboard();
	JoyPad* pad		 = new JoyPad();
	SceneMgr* smgr	 = new SceneMgr();
	MyRand* mrnd	 = new MyRand();

#ifdef _DEBUG
	FPS* fps		 = new FPS();
#endif // _DEBUG

	// ���b�Z�[�W���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_END) == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		key->KeyUpdate();
		pad->Pad_Update();
		smgr->SceneUpdate();
		smgr->SceneDraw();
		if (smgr->GetEndFlag() == true)
		{
			break;
		}
#ifdef _DEBUG
		//fps->Update();
		//fps->Draw();
		//fps->Waits();
#endif // _DEBUG
		ScreenFlip();
	}

#ifdef _DEBUG
	DEL_OBJ(fps);
#endif // _DEBUG

	DEL_OBJ(mrnd);
	DEL_OBJ(smgr);
	DEL_OBJ(pad);
	DEL_OBJ(key);

	InitGraph();
	DxLib_End();

	return 0;
}