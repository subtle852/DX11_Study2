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
			mBG_MAIN_01 = new GameObject();
			AddGameObject(eLayerType::BG, mBG_MAIN_01);
			MeshRenderer* mr = mBG_MAIN_01->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_BG_MAIN_01"));
			mBG_MAIN_01->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 50.0f));
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
			mBG_MAIN_01->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
				texture.get()->GetImageRatioOfHeight(), 0.0f))
				* 13.0f);
			//player->AddComponent<CameraScript>();

			mUI_MAIN_ENTER = new GameObject();
			AddGameObject(eLayerType::BG, mUI_MAIN_ENTER);
			MeshRenderer* mr2 = mUI_MAIN_ENTER->AddComponent<MeshRenderer>();
			mr2->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr2->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_ENTER"));
			mUI_MAIN_ENTER->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.05f, 49.0f));
			texture
				= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
			mUI_MAIN_ENTER->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
				texture.get()->GetImageRatioOfHeight(), 0.0f))
				* 13.0f);
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
				if (mBG_MAIN_02 == nullptr)
				{
					mBG_MAIN_02 = new GameObject();
					AddGameObject(eLayerType::BG, mBG_MAIN_02);
					MeshRenderer* mr = mBG_MAIN_02->AddComponent<MeshRenderer>();
					mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
					mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_BG_MAIN_02"));
					mBG_MAIN_02->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 48.0f));
					std::shared_ptr<Texture> texture
						= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
					mBG_MAIN_02->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
						texture.get()->GetImageRatioOfHeight(), 0.0f))
						* 13.0f);
					//player->AddComponent<CameraScript>();

					mMainEnterCount = 1;
				}
			}
		}

		if (mMainEnterCount == 0)
		{
			Transform* mUI_MAIN_ENTER_tr = mUI_MAIN_ENTER->GetComponent<Transform>();
			Vector3 mUI_MAIN_ENTER_scale = mUI_MAIN_ENTER_tr->GetScale();

			if (mUI_MAIN_ENTER_scale.x <= 6.4f)
			{
				mUI_MAIN_ENTER_SizeState = true;
			}
			else if (mUI_MAIN_ENTER_scale.x > 6.5f)
			{
				mUI_MAIN_ENTER_SizeState = false;
			}

			if (mUI_MAIN_ENTER_SizeState == true)
			{
				mUI_MAIN_ENTER_scale.x += 0.2f * Time::DeltaTime();
				mUI_MAIN_ENTER_scale.y += 0.2f * Time::DeltaTime();
				mUI_MAIN_ENTER_scale.z += 0.2f * Time::DeltaTime();

				mUI_MAIN_ENTER_tr->SetScale(mUI_MAIN_ENTER_scale);
			}
			else//(mSizeState == false)
			{
				mUI_MAIN_ENTER_scale.x -= 0.2f * Time::DeltaTime();
				mUI_MAIN_ENTER_scale.y -= 0.2f * Time::DeltaTime();
				mUI_MAIN_ENTER_scale.z -= 0.2f * Time::DeltaTime();

				mUI_MAIN_ENTER_tr->SetScale(mUI_MAIN_ENTER_scale);
			}
		}

		if (mMainEnterCount == 1)
		{
			if (mUI_MAIN_MENU_BAR == nullptr)
			{
				mUI_MAIN_MENU_BAR = new GameObject();
				AddGameObject(eLayerType::BG, mUI_MAIN_MENU_BAR);
				MeshRenderer* mr2 = mUI_MAIN_MENU_BAR->AddComponent<MeshRenderer>();
				mr2->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr2->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_MENU_BAR"));
				mUI_MAIN_MENU_BAR->GetComponent<Transform>()->SetPosition(Vector3(0.01f, -0.12f, 47.0f));
				//mUI_SELECT_BAR->GetComponent<Transform>()->SetPosition(Vector3(0.01f, -0.29f, 47.0f));
				std::shared_ptr<Texture> texture
					= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
				mUI_MAIN_MENU_BAR->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
					texture.get()->GetImageRatioOfHeight(), 0.0f))
					* 13.0f);
			}
			if (mUI_MAIN_MENU == nullptr)
			{
				mUI_MAIN_MENU = new GameObject();
				AddGameObject(eLayerType::BG, mUI_MAIN_MENU);
				MeshRenderer* mr3 = mUI_MAIN_MENU->AddComponent<MeshRenderer>();
				mr3->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr3->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_MENU"));
				mUI_MAIN_MENU->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 46.0f));
				std::shared_ptr<Texture> texture
					= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
				mUI_MAIN_MENU->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
					texture.get()->GetImageRatioOfHeight(), 0.0f))
					* 13.0f);
			}
			if (mUI_MAIN_CHAR == nullptr)
			{
				mUI_MAIN_CHAR = new GameObject();
				AddGameObject(eLayerType::BG, mUI_MAIN_CHAR);
				MeshRenderer* mr = mUI_MAIN_CHAR->AddComponent<MeshRenderer>();
				mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_MAIN_CHAR"));
				mUI_MAIN_CHAR->GetComponent<Transform>()->SetPosition(Vector3(0.1f, 0.0f, 45.0f));
				std::shared_ptr<Texture> texture
					= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
				mUI_MAIN_CHAR->GetComponent<Transform>()->SetScale((Vector3(texture.get()->GetImageRatioOfWidth(),
					texture.get()->GetImageRatioOfHeight(), 0.0f))
					* 13.0f);
			}

			Transform* mUI_MAIN_CHAR_tr = mUI_MAIN_CHAR->GetComponent<Transform>();
			Vector3 mUI_MAIN_CHAR_scale = mUI_MAIN_CHAR_tr->GetScale();

			if (mUI_MAIN_CHAR_scale.x <= 6.4f)
			{
				mUI_MAIN_CHAR_SizeState = true;
			}
			else if (mUI_MAIN_CHAR_scale.x > 6.7f)
			{
				mUI_MAIN_CHAR_SizeState = false;
			}

			if (mUI_MAIN_CHAR_SizeState == true)
			{
				mUI_MAIN_CHAR_scale.x += 0.4f * Time::DeltaTime();
				mUI_MAIN_CHAR_scale.y += 0.4f * Time::DeltaTime();
				mUI_MAIN_CHAR_scale.z += 0.4f * Time::DeltaTime();

				mUI_MAIN_CHAR_tr->SetScale(mUI_MAIN_CHAR_scale);
			}
			else//(mUI_CHAR_SizeState == false)
			{
				mUI_MAIN_CHAR_scale.x -= 0.4f * Time::DeltaTime();
				mUI_MAIN_CHAR_scale.y -= 0.4f * Time::DeltaTime();
				mUI_MAIN_CHAR_scale.z -= 0.4f * Time::DeltaTime();

				mUI_MAIN_CHAR_tr->SetScale(mUI_MAIN_CHAR_scale);
			}


			if (Input::GetKeyDown(eKeyCode::W))
			{
				if (mMenuNumber != static_cast<int>(MenuNumber::StoryMode))
					mMenuNumber--;
			}
			if (Input::GetKeyDown(eKeyCode::S))
			{
				if (mMenuNumber != static_cast<int>(MenuNumber::ExitGame))
					mMenuNumber++;
			}

			Transform* mUI_MAIN_SELECT_BAR_tr = mUI_MAIN_MENU_BAR->GetComponent<Transform>();
			Vector3 mUI_MAIN_SELECT_BAR_pos = mUI_MAIN_SELECT_BAR_tr->GetPosition();

			switch (mMenuNumber)
			{
			case static_cast<int>(MenuNumber::StoryMode):
				mUI_MAIN_SELECT_BAR_pos.y = -0.12f;
				break;
			case static_cast<int>(MenuNumber::NetworkGame):
				mUI_MAIN_SELECT_BAR_pos.y = -0.29f - (0.17f * 0) - 0.01f;
				break;
			case static_cast<int>(MenuNumber::ExtraGameModex):
				mUI_MAIN_SELECT_BAR_pos.y = -0.29f - (0.17f * 1) - 0.03f;
				break;
			case static_cast<int>(MenuNumber::UbisoftConnect):
				mUI_MAIN_SELECT_BAR_pos.y = -0.29f - (0.17f * 2) - 0.04f;
				break;
			case static_cast<int>(MenuNumber::Achievements):
				mUI_MAIN_SELECT_BAR_pos.y = -0.29f - (0.17f * 3) - 0.06f;
				break;
			case static_cast<int>(MenuNumber::Leaderboards):
				mUI_MAIN_SELECT_BAR_pos.y = -0.29f - (0.17f * 4) - 0.08f;
				break;
			case static_cast<int>(MenuNumber::HelpNOptions):
				mUI_MAIN_SELECT_BAR_pos.y = -0.29f - (0.17f * 5) - 0.09f;
				break;
			case static_cast<int>(MenuNumber::ExitGame):
				mUI_MAIN_SELECT_BAR_pos.y = -0.29f - (0.17f * 6) - 0.1f;
				break;
			default:
				break;
			}
			mUI_MAIN_SELECT_BAR_tr->SetPosition(mUI_MAIN_SELECT_BAR_pos);
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