#include "yaTitleScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCameraScript.h"
#include "yaCamera.h"
#include "yaInput.h"
#include "yaSceneManager.h"

namespace ya
{
	TitleScene::TitleScene()
		: mTitleEnterCount(0)
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		// TITLE
		{
			mBG_01 = new GameObject();
			AddGameObject(eLayerType::Player, mBG_01);
			MeshRenderer* mr = mBG_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_TITLE01"));
			mBG_01->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			//player->AddComponent<CameraScript>();
		}

		//Main Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::ENTER))
		{
			//if (mTitleEnterCount > 1)
			{
				SceneManager::LoadScene(L"MainScene");
			}

			//else
			//{
			//	GameObject* mBG_02 = new GameObject();
			//	AddGameObject(eLayerType::Player, mBG_02);
			//	MeshRenderer* mr = mBG_02->AddComponent<MeshRenderer>();
			//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			//	mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_TITLE02"));
			//	mBG_02->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			//	//player->AddComponent<CameraScript>();

			//	mTitleEnterCount = 1;
			//}
		}

		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render()
	{
		Scene::Render();
	}

	void TitleScene::OnEnter()
	{

	}

	void TitleScene::OnExit()
	{

	}
}