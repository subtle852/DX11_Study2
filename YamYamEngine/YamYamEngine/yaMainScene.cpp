#include "yaMainScene.h"
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
			AddGameObject(eLayerType::BG, mBG_01);
			MeshRenderer* mr = mBG_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"BGBasicMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_MAIN_01"));
			mBG_01->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 50.0f));
			mBG_01->GetComponent<Transform>()->SetScale(Vector3(6.4f, 6.4f, 6.4f));
			//player->AddComponent<CameraScript>();

			mUI_ENTER = new GameObject();
			AddGameObject(eLayerType::BG, mUI_ENTER);
			MeshRenderer* mr2 = mUI_ENTER->AddComponent<MeshRenderer>();
			mr2->SetMesh(Resources::Find<Mesh>(L"BGBasicMesh"));
			mr2->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_ENTER"));
			mUI_ENTER->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.05f, 49.0f));
			mUI_ENTER->GetComponent<Transform>()->SetScale(Vector3(6.4f, 6.4f, 6.4f));
		}

		//Main Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		//camera->AddComponent<CameraScript>();
	}

	void MainScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::ENTER))
		{
			if (mMainEnterCount > 0)
			{
				SceneManager::LoadScene(L"SelectScene");
			}

			else
			{
				if (mBG_02 == nullptr)
				{
					mBG_02 = new GameObject();
					AddGameObject(eLayerType::BG, mBG_02);
					MeshRenderer* mr = mBG_02->AddComponent<MeshRenderer>();
					mr->SetMesh(Resources::Find<Mesh>(L"BGBasicMesh"));
					mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_MAIN_02"));
					mBG_02->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 48.0f));
					mBG_02->GetComponent<Transform>()->SetScale(Vector3(6.4f, 6.4f, 6.4f));
					//player->AddComponent<CameraScript>();

					mMainEnterCount = 1;
				}
			}
		}

		if (mMainEnterCount == 0)
		{
			Transform* mUI_ENTER_tr = mUI_ENTER->GetComponent<Transform>();
			Vector3 mUI_ENTER_scale = mUI_ENTER_tr->GetScale();

			if (mUI_ENTER_scale.x <= 6.4f)
			{
				mUI_ENTER_SizeState = true;
			}
			else if (mUI_ENTER_scale.x > 6.8f)
			{
				mUI_ENTER_SizeState = false;
			}

			if (mUI_ENTER_SizeState == true)
			{
				mUI_ENTER_scale.x += 0.7f * Time::DeltaTime();
				mUI_ENTER_scale.y += 0.7f * Time::DeltaTime();
				mUI_ENTER_scale.z += 0.7f * Time::DeltaTime();

				mUI_ENTER_tr->SetScale(mUI_ENTER_scale);
			}
			else//(mSizeState == false)
			{
				mUI_ENTER_scale.x -= 0.7f * Time::DeltaTime();
				mUI_ENTER_scale.y -= 0.7f * Time::DeltaTime();
				mUI_ENTER_scale.z -= 0.7f * Time::DeltaTime();

				mUI_ENTER_tr->SetScale(mUI_ENTER_scale);
			}
		}

		if (mMainEnterCount == 1)
		{
			if (mUI_SELECT_BAR == nullptr)
			{
				mUI_SELECT_BAR = new GameObject();
				AddGameObject(eLayerType::BG, mUI_SELECT_BAR);
				MeshRenderer* mr2 = mUI_SELECT_BAR->AddComponent<MeshRenderer>();
				mr2->SetMesh(Resources::Find<Mesh>(L"BGBasicMesh"));
				mr2->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_SELECT_BAR"));
				mUI_SELECT_BAR->GetComponent<Transform>()->SetPosition(Vector3(0.01f, -0.12f, 47.0f));
				//mUI_SELECT_BAR->GetComponent<Transform>()->SetPosition(Vector3(0.01f, -0.29f, 47.0f));
				mUI_SELECT_BAR->GetComponent<Transform>()->SetScale(Vector3(6.4f, 6.4f, 6.4f));
			}
			if (mUI_SELECT == nullptr)
			{
				mUI_SELECT = new GameObject();
				AddGameObject(eLayerType::BG, mUI_SELECT);
				MeshRenderer* mr3 = mUI_SELECT->AddComponent<MeshRenderer>();
				mr3->SetMesh(Resources::Find<Mesh>(L"BGBasicMesh"));
				mr3->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_SELECT"));
				mUI_SELECT->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 46.0f));
				mUI_SELECT->GetComponent<Transform>()->SetScale(Vector3(6.4f, 6.4f, 6.4f));
			}
			if (mUI_CHAR == nullptr)
			{
				mUI_CHAR = new GameObject();
				AddGameObject(eLayerType::BG, mUI_CHAR);
				MeshRenderer* mr = mUI_CHAR->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"BGBasicMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_CHAR"));
				mUI_CHAR->GetComponent<Transform>()->SetPosition(Vector3(0.1f, 0.0f, 45.0f));
				mUI_CHAR->GetComponent<Transform>()->SetScale(Vector3(6.4f, 6.4f, 6.4f));
			}

			Transform* mUI_CHAR_tr = mUI_CHAR->GetComponent<Transform>();
			Vector3 mUI_CHAR_scale = mUI_CHAR_tr->GetScale();

			if (mUI_CHAR_scale.x <= 6.4f)
			{
				mUI_CHAR_SizeState = true;
			}
			else if (mUI_CHAR_scale.x > 7.0f)
			{
				mUI_CHAR_SizeState = false;
			}

			if (mUI_CHAR_SizeState == true)
			{
				mUI_CHAR_scale.x += 0.7f * Time::DeltaTime();
				mUI_CHAR_scale.y += 0.7f * Time::DeltaTime();
				mUI_CHAR_scale.z += 0.7f * Time::DeltaTime();

				mUI_CHAR_tr->SetScale(mUI_CHAR_scale);
			}
			else//(mUI_CHAR_SizeState == false)
			{
				mUI_CHAR_scale.x -= 0.7f * Time::DeltaTime();
				mUI_CHAR_scale.y -= 0.7f * Time::DeltaTime();
				mUI_CHAR_scale.z -= 0.7f * Time::DeltaTime();

				mUI_CHAR_tr->SetScale(mUI_CHAR_scale);
			}


			if (Input::GetKeyDown(eKeyCode::W))
			{
				if (mSelectNumber != static_cast<int>(SelectNumber::StoryMode))
					mSelectNumber--;
			}
			if (Input::GetKeyDown(eKeyCode::S))
			{
				if (mSelectNumber != static_cast<int>(SelectNumber::ExitGame))
					mSelectNumber++;
			}

			Transform* mUI_SELECT_BAR_tr = mUI_SELECT_BAR->GetComponent<Transform>();
			Vector3 mUI_SELECT_BAR_pos = mUI_SELECT_BAR_tr->GetPosition();

			switch (mSelectNumber)
			{
			case static_cast<int>(SelectNumber::StoryMode):
				mUI_SELECT_BAR_pos.y = -0.12f;
				break;
			case static_cast<int>(SelectNumber::NetworkGame):
				mUI_SELECT_BAR_pos.y = -0.29f - (0.17f * 0);
				break;
			case static_cast<int>(SelectNumber::ExtraGameModex):
				mUI_SELECT_BAR_pos.y = -0.29f - (0.17f * 1) - 0.02f;
				break;
			case static_cast<int>(SelectNumber::UbisoftConnect):
				mUI_SELECT_BAR_pos.y = -0.29f - (0.17f * 2) - 0.03f;
				break;
			case static_cast<int>(SelectNumber::Achievements):
				mUI_SELECT_BAR_pos.y = -0.29f - (0.17f * 3) - 0.04f;
				break;
			case static_cast<int>(SelectNumber::Leaderboards):
				mUI_SELECT_BAR_pos.y = -0.29f - (0.17f * 4) - 0.06f;
				break;
			case static_cast<int>(SelectNumber::HelpNOptions):
				mUI_SELECT_BAR_pos.y = -0.29f - (0.17f * 5) - 0.07f;
				break;
			case static_cast<int>(SelectNumber::ExitGame):
				mUI_SELECT_BAR_pos.y = -0.29f - (0.17f * 6) - 0.08f;
				break;
			default:
				break;
			}
			mUI_SELECT_BAR_tr->SetPosition(mUI_SELECT_BAR_pos);
		}

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