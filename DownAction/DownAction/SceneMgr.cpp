/*
学籍番号：j17086
名前：亀田朋来
*/

#include"SceneMgr.h"

SceneMgr::SceneMgr()
{
	mpScene	 = nullptr;
	mpScene	 = new TitleScene();
	preScene = mpScene->GetNowScene();
	gra		 = nullptr;
	gra		 = new Graphics();
	df		 = nullptr;
	df		 = new DataFile();
	sc		 = nullptr;
	sc		 = new Score();
	imgr	 = new ItemMgr();
	tw		 = new TimeWatch();
}

SceneMgr::~SceneMgr()
{
	DEL_OBJ(tw);
	DEL_OBJ(imgr);
	DEL_OBJ(sc);
	DEL_OBJ(df);
	DEL_OBJ(gra);
	DEL_OBJ(mpScene);
}

void SceneMgr::ChangeScene() 
{
	DEL_OBJ(mpScene);

	switch (mpScene->GetNowScene())
	{
	case SceneName::eTitle:
		mpScene = new TitleScene();
		break;
	case SceneName::eGame:
		mpScene = new GameScene();
		break;
	case SceneName::eResult:
		mpScene = new ResultScene();
		break;
	case SceneName::eResult2:
		mpScene = new ResultScene2();
		break;
	case SceneName::eIC_Scene:
		mpScene = new ItemChangeScene();
		break;
	default:
		break;
	}
}

void SceneMgr::SceneUpdate() 
{
	mpScene->EndInput();
	preScene = mpScene->GetNowScene();
	mpScene->Update();
	if (mpScene->GetNowScene() != preScene)
	{
		ChangeScene();
	}
}

void SceneMgr::SceneDraw()
{
	mpScene->Draw();
}

bool SceneMgr::GetEndFlag()
{
	return mpScene->endFlag;
}