#include "yaSceneManager.h"

#include "yaTitleScene.h"
#include "yaMainScene.h"
#include "yaSelectScene.h"
#include "yaTownScene.h"
#include "yaPlayScene.h"

namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes;

	void SceneManager::Initialize()
	{
		mActiveScene = new TitleScene();
		mScenes.insert(std::make_pair(L"TitleScene", mActiveScene));
		mActiveScene = new MainScene();
		mScenes.insert(std::make_pair(L"MainScene", mActiveScene));
		mActiveScene = new SelectScene();
		mScenes.insert(std::make_pair(L"SelectScene", mActiveScene));
		mActiveScene = new TownScene();
		mScenes.insert(std::make_pair(L"TownScene", mActiveScene));
		mActiveScene = new PlayScene();
		mScenes.insert(std::make_pair(L"PlayScene", mActiveScene));


		auto itr = mScenes.find(L"TitleScene");
		mActiveScene = itr->second;
		
		for (auto itr = mScenes.begin(); itr != mScenes.end(); itr++)
		{
			itr->second->Initialize();
		}

		//mActiveScene->Initialize();
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render()
	{
		mActiveScene->Render();
	}

	void SceneManager::Release()
	{
		for (auto iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	Scene* SceneManager::LoadScene(std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene->OnExit();
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}
}
