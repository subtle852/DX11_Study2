#pragma once
#include "..\Engine_SOURCE\yaSceneManager.h"

#include "yaTitleScene.h"
#include "yaMainScene.h"
#include "yaSelectScene.h"
#include "yaTownScene.h"
#include "yaPlayScene.h"
#include "yaShopScene.h"
#include "yaSubspace01Scene.h"
#include "yaSubspace02Scene.h"
#include "yaBoss01Scene.h"
#include "yaEndingScene.h"


#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\YamYamEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\YamYamEngine.lib")
#endif



//#include "..\YamYamEngine\\yaPlayScene.h"
//#include "yaSceneManager.h"
namespace ya
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<MainScene>(L"MainScene");
		SceneManager::CreateScene<SelectScene>(L"SelectScene");
		SceneManager::CreateScene<TownScene>(L"TownScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<ShopScene>(L"ShopScene");
		SceneManager::CreateScene<Subspace01Scene>(L"Subspace01Scene");
		SceneManager::CreateScene<Subspace02Scene>(L"Subspace02Scene");
		SceneManager::CreateScene<Boss01Scene>(L"Boss01Scene");
		SceneManager::CreateScene<EndingScene>(L"EndingScene");

		SceneManager::SetActiveScene(L"PlayScene");
	}
}