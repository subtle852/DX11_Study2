#include "yaPlayScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCameraScript.h"
#include "yaCamera.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTime.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		// STAGE 01 - BG 
		{
			mBG_STAGE01_01 = new GameObject();
			mBG_STAGE01_01->SetName(L"BG_STAGE01_01");
			AddGameObject(eLayerType::Player, mBG_STAGE01_01);// Player로 설정
			MeshRenderer* mr = mBG_STAGE01_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_BG_STAGE01_01"));
			mBG_STAGE01_01->GetComponent<Transform>()->SetPosition(Vector3(0.0f, -0.38f, 50.0f));
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_STAGE01_01", L"..\\Resources\\SCENE\\STAGE01\\BG_STAGE01_01.png");
			mBG_STAGE01_01->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
				texture.get()->GetImageRatioOfHeight(), 0.0f))
				* 265.0f);
			//player->AddComponent<CameraScript>();


			//GameObject* mBG_02 = new GameObject();
			//mBG_02->SetName(L"BG_02");
			//AddGameObject(eLayerType::Player, mBG_02);// Player로 설정
			//MeshRenderer* mr2 = mBG_02->AddComponent<MeshRenderer>();
			//mr2->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			//mr2->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_STAGE01_BG"));
			//mBG_02->GetComponent<Transform>()->SetPosition(Vector3(1.0f, 0.0f, 0.0f));
			////player->AddComponent<CameraScript>();

			//mBG_02->GetComponent<Transform>()->SetParent(mBG_01->GetComponent<Transform>());

			//mBG_01->GetComponent<Transform>()->SetPosition(Vector3(-3.0f, 0.0f, 1.0001f));
			//mBG_01->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, 45.f));
		}

		{
			mUI_STAGE01_STATE = new GameObject();
			mUI_STAGE01_STATE->SetName(L"UI_STAGE01_STATE");
			AddGameObject(eLayerType::UI, mUI_STAGE01_STATE);// UI로 설정
			MeshRenderer* mr3 = mUI_STAGE01_STATE->AddComponent<MeshRenderer>();
			mr3->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr3->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_STAGE01_STATE"));
			mUI_STAGE01_STATE->GetComponent<Transform>()->SetPosition(Vector3(-2.1f, 1.4f, 49.f));
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_STAGE01_STATE", L"..\\Resources\\SCENE\\STAGE01\\UI_STAGE01_STATE.png");
			mUI_STAGE01_STATE->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
				texture.get()->GetImageRatioOfHeight(), 0.0f))
				* 4.0f);
			//player->AddComponent<CameraScript>();
		}

		//Main Camera
		{
			GameObject* camera = new GameObject();
			camera->SetName(L"MainCamera");
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);// UI를 안보이게 설정
			camera->AddComponent<CameraScript>();
		}

		//UI Camera
		{
			GameObject* camera = new GameObject();
			camera->SetName(L"UICamera");
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);// Player를 안보이게 설정
			//camera->AddComponent<CameraScript>();
		}

	}

	void PlayScene::Update()
	{
		//Transform* tr = mBG_PLAY_01->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();

		//pos.x -= 1.0f * Time::DeltaTime();

		//tr->SetPosition(pos);

		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{

	}
}