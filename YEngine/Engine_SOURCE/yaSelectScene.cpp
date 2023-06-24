#include "yaSelectScene.h"
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
	SelectScene::SelectScene()
	{
	}
	SelectScene::~SelectScene()
	{
	}
	void SelectScene::Initialize()
	{
		{
			mBG_01 = new GameObject();
			AddGameObject(eLayerType::Player, mBG_01);
			MeshRenderer* mr = mBG_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_SELECT"));
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

	void SelectScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::ENTER))
		{
			SceneManager::LoadScene(L"TownScene");
		}

		Scene::Update();
	}

	void SelectScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void SelectScene::Render()
	{
		Scene::Render();
	}

	void SelectScene::OnEnter()
	{

	}

	void SelectScene::OnExit()
	{

	}
}