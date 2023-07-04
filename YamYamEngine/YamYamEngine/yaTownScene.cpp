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
			mBG_TOWN_MAP = new GameObject();
			AddGameObject(eLayerType::BG, mBG_TOWN_MAP);
			MeshRenderer* mr = mBG_TOWN_MAP->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_BG_TOWN_MAP"));
			mBG_TOWN_MAP->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 50.0f));
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_TOWN_MAP", L"..\\Resources\\SCENE\\04_TOWN\\BG_TOWN_MAP.png");
			mBG_TOWN_MAP->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
				texture.get()->GetImageRatioOfHeight(), 0.0f))
				* 13.0f);
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