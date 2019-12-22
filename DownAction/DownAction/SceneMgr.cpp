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
}

SceneMgr::~SceneMgr()
{
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
	default:
		break;
	}
}

void SceneMgr::SceneUpdate() 
{
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