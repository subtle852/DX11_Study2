#include "yaSceneManager.h"
//#include "yaPlayScene.h"



namespace ya
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes;

	void SceneManager::Initialize()
	{

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
		for (auto& iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	//bool SceneManager::CreateScene(std::wstring name, Scene* scene)
	//{
	//	std::map<std::wstring, Scene*>::iterator iter
	//		= mScenes.find(name);

	//	if (iter != mScenes.end())
	//		return false;

	//	mScenes.insert(std::make_pair(name, scene));
	//	scene->Initialize();
	//	return true;
	//}

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
