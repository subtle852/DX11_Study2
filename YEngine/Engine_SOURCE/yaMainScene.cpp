#include "yaMainScene.h"
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
	MainScene::MainScene()
	{
	}
	MainScene::~MainScene()
	{
	}
	void MainScene::Initialize()
	{
		{
			mBG_01 = new GameObject();
			AddGameObject(eLayerType::Player, mBG_01);
			MeshRenderer* mr = mBG_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_MAIN_01"));
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

	void MainScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::ENTER))
		{
			SceneManager::LoadScene(L"SelectScene");
		}

		//{
		//	GameObject* BG_MAIN_02 = new GameObject();
		//	AddGameObject(eLayerType::Player, BG_MAIN_02);
		//	MeshRenderer* mr = BG_MAIN_02->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_MAIN_02"));
		//	BG_MAIN_02->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		//	//player->AddComponent<CameraScript>();
		//}

		Scene::Update();
	}

	void MainScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void MainScene::Render()
	{
		Scene::Render();
	}

	void MainScene::OnEnter()
	{

	}

	void MainScene::OnExit()
	{

	}
}