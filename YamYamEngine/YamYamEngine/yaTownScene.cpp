#include "yaTownScene.h"
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
	TownScene::TownScene()
	{
	}
	TownScene::~TownScene()
	{
	}
	void TownScene::Initialize()
	{
		{
			mBG_01 = new GameObject();
			AddGameObject(eLayerType::BG, mBG_01);
			MeshRenderer* mr = mBG_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_TOWN"));
			mBG_01->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			//player->AddComponent<CameraScript>();
		}

		//Main Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::BG, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();
	}

	void TownScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::ENTER))
		{
			SceneManager::LoadScene(L"PlayScene");
		}

		Scene::Update();
	}

	void TownScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TownScene::Render()
	{
		Scene::Render();
	}

	void TownScene::OnEnter()
	{

	}

	void TownScene::OnExit()
	{

	}
}