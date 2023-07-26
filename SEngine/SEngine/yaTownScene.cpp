#include "yaTownScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMesh.h"
#include "yaCameraScript.h"
#include "yaCamera.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaAnimator.h"
#include "yaRenderer.h"
#include "yaMiniScript.h"

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
		// BG 
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_TOWN_MAP", L"..\\Resources\\SCENE\\STAGE01\\BG_TOWN_MAP.png");

			mBG_TOWN_MAP = object::Instantiate<GameObject>(Vector3(0.0f, 0.0f, 50.0f)
				, Vector3(texture.get()->GetImageRatioOfWidth(), texture.get()->GetImageRatioOfHeight(), 0.0f) * 15.0f
				, eLayerType::Player);
			mBG_TOWN_MAP->SetName(L"BG_TOWN_MAP");

			MeshRenderer* mr = mBG_TOWN_MAP->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_BG_TOWN_MAP"));
			//player->AddComponent<CameraScript>();
		}

		// 애니메이션
		{
			GameObject* mPlayer
				= object::Instantiate<GameObject>(Vector3(-2.25f, 1.65f, 40.f)
					, Vector3::One * 4.0f
					, eLayerType::Player);
			mPlayer->SetName(L"MINI");

			Collider2D* cd = mPlayer->AddComponent<Collider2D>();
			cd->SetSize(Vector2(1.0f, 1.0f));

			MeshRenderer* mr = mPlayer->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimationMaterial"));

			std::shared_ptr<Texture> atlas
				= Resources::Load<Texture>(L"MINI_CHAR", L"..\\Resources\\Texture\\MINI_CHAR.png");
			Animator* at = mPlayer->AddComponent<Animator>();
			at->Create(L"MINI_CHAR", atlas, enums::eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(56.0f / 4.0f, 16.0f), 4);
			at->PlayAnimation(L"MINI_CHAR", true);

			mPlayer->AddComponent<MiniScript>();
		}

		// Light
		{
			GameObject* light = new GameObject();
			light->SetName(L"Smile");
			AddGameObject(eLayerType::Light, light);
			Light* lightComp = light->AddComponent<Light>();
			lightComp->SetType(eLightType::Directional);
			lightComp->SetColor(Vector4(1.0f, 1.0f, 1.0f, 1.0f));
		}

		// Main Camera
		Camera* cameraComp = nullptr;

		{
			GameObject* camera = new GameObject();
			camera->SetName(L"MainCamera");
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);// UI를 안보이게 설정
			camera->AddComponent<CameraScript>();
			renderer::cameras.push_back(cameraComp);// Main Camera 렌더러에 추가
			renderer::mainCamera = cameraComp;
		}

		// UI Camera
		{
			GameObject* camera = new GameObject();
			camera->SetName(L"UICamera");
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);// Player를 안보이게 설정
			cameraComp->TurnLayerMask(eLayerType::Monster, false);
			//camera->AddComponent<CameraScript>();
		}
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