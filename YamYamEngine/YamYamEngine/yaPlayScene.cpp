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
#include "yaGridScript.h"
#include "yaObject.h"
#include "yaRenderer.h"
#include "yaCollider2D.h"
#include "yaCollisionManager.h"
#include "yaPlayerScript.h"
#include "yaAnimator.h"

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
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);

		// STAGE 01 - BG 
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_STAGE01_01", L"..\\Resources\\SCENE\\STAGE01\\BG_STAGE01_01.png");

			mBG_STAGE01_01 = object::Instantiate<GameObject>(Vector3(0.0f, -0.34f, 50.0f)
				, Vector3(texture.get()->GetImageRatioOfWidth(), texture.get()->GetImageRatioOfHeight(), 0.0f) * 272.0f
				, eLayerType::Player);// Player로 설정
			mBG_STAGE01_01->SetName(L"BG_STAGE01_01");

			MeshRenderer* mr = mBG_STAGE01_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_BG_STAGE01_01"));
			//player->AddComponent<CameraScript>();
		}

		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_STAGE01_STATE", L"..\\Resources\\SCENE\\STAGE01\\UI_STAGE01_STATE.png");

			mUI_STAGE01_STATE = object::Instantiate<GameObject>(Vector3(-2.1f, 1.4f, 49.f)
				, Vector3(texture.get()->GetImageRatioOfWidth(), texture.get()->GetImageRatioOfHeight(), 0.0f) * 4.0f
				, eLayerType::Player);// UI로 설정해야하는데 충돌 확인을 위해 Player로 설정해둔 상태
			mUI_STAGE01_STATE->SetName(L"UI_STAGE01_STATE");

			MeshRenderer* mr3 = mUI_STAGE01_STATE->AddComponent<MeshRenderer>();
			mr3->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr3->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_STAGE01_STATE"));

			//mUI_STAGE01_STATE->AddComponent<Collider2D>();
			Collider2D* cd = mUI_STAGE01_STATE->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));

			//{// 콜라이더 추가하고 comps를 불러오는 GetComponents 활용법
			//	cd = mUI_STAGE01_STATE->AddComponent<Collider2D>();
			//	std::vector<Collider2D*> comps
			//		= mUI_STAGE01_STATE->GetComponents<Collider2D>();
			//}

			//player->AddComponent<CameraScript>();

			//// 부모 자식 Transform
			//{
			//	GameObject* mTemp = new GameObject();
			//	mTemp->SetName(L"Temp");
			//	AddGameObject(eLayerType::UI, mTemp);
			//	MeshRenderer* mr2 = mTemp->AddComponent<MeshRenderer>();
			//	mr2->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			//	mr2->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_STAGE01_STATE"));
			//	mTemp->GetComponent<Transform>()->SetPosition(Vector3(1.0f, 0.0f, 0.0f));
			//	//player->AddComponent<CameraScript>();

			//	mTemp->GetComponent<Transform>()->SetParent(mUI_STAGE01_STATE->GetComponent<Transform>());

			//	mUI_STAGE01_STATE->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			//	mUI_STAGE01_STATE->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, 45.f));

			//	Vector3 pos = mUI_STAGE01_STATE->GetComponent<Transform>()->GetRotation();
			//}
		}

		{// 충돌을 위한 오브젝트
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_STAGE01_STATE", L"..\\Resources\\SCENE\\STAGE01\\UI_STAGE01_STATE.png");

			GameObject* monster = object::Instantiate<GameObject>(Vector3(-2.1f, -1.4f, 49.f)
				, Vector3(texture.get()->GetImageRatioOfWidth(), texture.get()->GetImageRatioOfHeight(), 0.0f) * 4.0f
				, eLayerType::Monster);
			monster->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, 45.0f));
			monster->SetName(L"monster");

			MeshRenderer* mr3 = monster->AddComponent<MeshRenderer>();
			mr3->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr3->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_STAGE01_STATE"));

			//mUI_STAGE01_STATE->AddComponent<Collider2D>();
			Collider2D* cd = monster->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));

			std::shared_ptr<Texture> atlas
				= Resources::Load<Texture>(L"LinkSprite", L"..\\Resources\\Texture\\linkSprites.png");

			Animator* at = monster->AddComponent<Animator>();
			at->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f), 3);

			at->PlayAnimation(L"Idle", true);

			monster->AddComponent<PlayerScript>();
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
			//camera->AddComponent<CameraScript>();
		}

		//// Grid
		//{
		//	GameObject* grid = new GameObject();
		//	grid->SetName(L"Grid");
		//	AddGameObject(eLayerType::Grid, grid);
		//	MeshRenderer* mr = grid->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		//	GridScript* gridSc = grid->AddComponent<GridScript>();
		//	gridSc->SetCamera(cameraComp);
		//}
	}

	void PlayScene::Update()
	{
		//Transform* tr = mBG_PLAY_01->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();

		//pos.x -= 1.0f * Time::DeltaTime();

		//tr->SetPosition(pos);

		if (Input::GetKeyDown(eKeyCode::ENTER))
		{
			SceneManager::LoadScene(L"ShopScene");
		}


		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Vector3 pos(640, 360, 0.0f);
		Vector3 pos2(640, 360, 1000.0f);
		Viewport viewport;
		viewport.width = 1280.0f;
		viewport.height = 720.0f;
		viewport.x = 0;
		viewport.y = 0;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		pos = viewport.Unproject(pos, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);
		pos2 = viewport.Unproject(pos2, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);

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