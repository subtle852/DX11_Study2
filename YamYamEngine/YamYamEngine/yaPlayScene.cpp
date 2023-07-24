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
				, eLayerType::UI);
			mUI_STAGE01_STATE->SetName(L"UI_STAGE01_STATE");

			MeshRenderer* mr = mUI_STAGE01_STATE->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial_UI_STAGE01_STATE"));

			Collider2D* cd = mUI_STAGE01_STATE->AddComponent<Collider2D>();
			cd->SetCenter(Vector2(0.0f, 0.0f));

			//{// 콜라이더 추가하고 comps를 불러오는 GetComponents 활용법
			//	cd = mUI_STAGE01_STATE->AddComponent<Collider2D>();
			//	std::vector<Collider2D*> comps
			//		= mUI_STAGE01_STATE->GetComponents<Collider2D>();
			//}

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

		// 애니메이션
		{
			GameObject* player 
				= object::Instantiate<GameObject>(Vector3(-2.0f, 0.0f, 40.f)
				, Vector3::One * 5
				, eLayerType::Monster);
			player->SetName(L"Ramona");

			Collider2D* cd = player->AddComponent<Collider2D>();
			cd->SetSize(Vector2(0.3f, 0.3f));

			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimationMaterial"));

			std::shared_ptr<Texture> atlas
				= Resources::Load<Texture>(L"Idle", L"..\\Resources\\Texture\\Idle.png");
			Animator* at = player->AddComponent<Animator>();
			at->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(151.0f / 5.0f, 65.0f), 5);
			at->PlayAnimation(L"Idle", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Walk", L"..\\Resources\\Texture\\Walk.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Walk", atlas, Vector2(0.0f, 0.0f), Vector2(210.0f / 6.0f, 68.0f), 6);
			//at->PlayAnimation(L"Walk", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Run", L"..\\Resources\\Texture\\Run.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Run", atlas, Vector2(0.0f, 0.0f), Vector2(424.0f / 8.0f, 67.0f), 8);
			//at->PlayAnimation(L"Run", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Jump", L"..\\Resources\\Texture\\Jump.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Jump", atlas, Vector2(0.0f, 0.0f), Vector2(432.0f / 9.0f, 78.0f), 9);
			//at->PlayAnimation(L"Jump", true);
			 
			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"DJump", L"..\\Resources\\Texture\\DJump.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"DJump", atlas, Vector2(0.0f, 0.0f), Vector2(309.0f / 6.0f, 75.0f), 6);
			//at->PlayAnimation(L"DJump", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Guard", L"..\\Resources\\Texture\\Guard.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Guard", atlas, Vector2(0.0f, 0.0f), Vector2(219.0f / 5.0f, 70.0f), 5);
			//at->PlayAnimation(L"Guard", true);
			 
			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Evade", L"..\\Resources\\Texture\\Evade.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Evade", atlas, Vector2(0.0f, 0.0f), Vector2(399.0f / 7.0f, 64.0f), 7);
			//at->PlayAnimation(L"Evade", true);
			
			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Downed", L"..\\Resources\\Texture\\Downed.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Downed", atlas, Vector2(0.0f, 0.0f), Vector2(292.0f / 4.0f, 69.0f), 4);
			//at->PlayAnimation(L"Downed", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Held", L"..\\Resources\\Texture\\Held_.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Held", atlas, Vector2(0.0f, 0.0f), Vector2(106.0f / 2.0f, 64.0f), 2);
			//at->PlayAnimation(L"Held", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Behind", L"..\\Resources\\Texture\\Behind.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Behind", atlas, Vector2(0.0f, 0.0f), Vector2(150.0f / 3.0f, 69.0f), 3);
			//at->PlayAnimation(L"Behind", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Front", L"..\\Resources\\Texture\\Front.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Front", atlas, Vector2(0.0f, 0.0f), Vector2(192.0f / 4.0f, 70.0f), 4);
			//at->PlayAnimation(L"Front", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Stun", L"..\\Resources\\Texture\\Stun.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Stun", atlas, Vector2(0.0f, 0.0f), Vector2(92.0f / 2.0f, 66.0f), 2);
			//at->PlayAnimation(L"Stun", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"KnockDown", L"..\\Resources\\Texture\\KnockDown.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"KnockDown", atlas, Vector2(0.0f, 0.0f), Vector2(988.0f / 13.0f, 88.0f), 13);
			//at->PlayAnimation(L"KnockDown", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Revived", L"..\\Resources\\Texture\\Revived.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Revived", atlas, Vector2(0.0f, 0.0f), Vector2(592.0f / 8.0f, 160.0f), 8);
			//at->PlayAnimation(L"Revived", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"GetUp", L"..\\Resources\\Texture\\GetUp.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"GetUp", atlas, Vector2(0.0f, 0.0f), Vector2(675.0f / 9.0f, 86.0f), 9);
			//at->PlayAnimation(L"GetUp", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"StageClear", L"..\\Resources\\Texture\\StageClear.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"StageClear", atlas, Vector2(0.0f, 0.0f), Vector2(364.0f / 7.0f, 83.0f), 7);
			//at->PlayAnimation(L"StageClear", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"StageExit", L"..\\Resources\\Texture\\StageExit.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"StageExit", atlas, Vector2(0.0f, 0.0f), Vector2(986.0f / 21.0f, 78.0f), 21);
			//at->PlayAnimation(L"StageExit", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"NormalAttack1", L"..\\Resources\\Texture\\NormalAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"NormalAttack", atlas, Vector2(0.0f, 0.0f), Vector2(558.0f / 9.0f, 70.0f), 9);
			//at->PlayAnimation(L"NormalAttack", true);

			//// 공격 1,2,3 1애니메이션 진행중에 공격키 누르면 2 진행, 2 진행중에 공격키 누르면 3진행
			//std::shared_ptr<Texture> atlas
			//= Resources::Load<Texture>(L"NormalAttack1", L"..\\Resources\\Texture\\NormalAttack1.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"NormalAttack1", atlas, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);
			//at->PlayAnimation(L"NormalAttack1", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"NormalAttack2", L"..\\Resources\\Texture\\NormalAttack2.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"NormalAttack2", atlas, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);
			//at->PlayAnimation(L"NormalAttack2", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"NormalAttack3", L"..\\Resources\\Texture\\NormalAttack3.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"NormalAttack3", atlas, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);
			//at->PlayAnimation(L"NormalAttack3", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Kick", L"..\\Resources\\Texture\\Kick.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Kick", atlas, Vector2(0.0f, 0.0f), Vector2(310.0f / 5.0f, 70.0f), 5);
			//at->PlayAnimation(L"Kick", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"NormalWeaponAttack", L"..\\Resources\\Texture\\NormalWeaponAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"NormalWeaponAttack", atlas, Vector2(0.0f, 0.0f), Vector2(663.0f / 8.0f, 86.0f), 8);
			//at->PlayAnimation(L"NormalWeaponAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"RunSlideAttack", L"..\\Resources\\Texture\\RunSlideAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"RunSlideAttack", atlas, Vector2(0.0f, 0.0f), Vector2(328.0f / 5.0f, 66.0f), 5);
			//at->PlayAnimation(L"RunSlideAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"RunWeaponAttack", L"..\\Resources\\Texture\\RunWeaponAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"RunWeaponAttack", atlas, Vector2(0.0f, 0.0f), Vector2(752.0f / 8.0f, 70.0f), 8);
			//at->PlayAnimation(L"RunWeaponAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"BehindAttack", L"..\\Resources\\Texture\\BehindAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"BehindAttack", atlas, Vector2(0.0f, 0.0f), Vector2(240.0f / 6.0f, 69.0f), 6);
			//at->PlayAnimation(L"BehindAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"WeaponStabAttack", L"..\\Resources\\Texture\\WeaponStabAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"WeaponStabAttack", atlas, Vector2(0.0f, 0.0f), Vector2(394.0f / 5.0f, 71.0f), 5);
			//at->PlayAnimation(L"WeaponStabAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"WeaponDownAttack", L"..\\Resources\\Texture\\WeaponDownAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"WeaponDownAttack", atlas, Vector2(0.0f, 0.0f), Vector2(255.0f / 5.0f, 75.0f), 5);
			//at->PlayAnimation(L"WeaponDownAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"JumpSlideAttack", L"..\\Resources\\Texture\\JumpSlideAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"JumpSlideAttack", atlas, Vector2(0.0f, 0.0f), Vector2(384.0f / 6.0f, 68.0f), 6);
			//at->PlayAnimation(L"JumpSlideAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"RunJumpAttack", L"..\\Resources\\Texture\\RunJumpAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"RunJumpAttack", atlas, Vector2(0.0f, 0.0f), Vector2(581.0f / 7.0f, 89.0f), 7);
			//at->PlayAnimation(L"RunJumpAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"WeaponLand", L"..\\Resources\\Texture\\WeaponLand.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"WeaponLand", atlas, Vector2(0.0f, 0.0f), Vector2(612.0f / 9.0f, 78.0f), 9);
			//at->PlayAnimation(L"WeaponLand", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"WeaponSideAttack", L"..\\Resources\\Texture\\WeaponSideAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"WeaponSideAttack", atlas, Vector2(0.0f, 0.0f), Vector2(805.0f / 8.0f, 79.0f), 8);
			//at->PlayAnimation(L"WeaponSideAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"JumpDownAttack", L"..\\Resources\\Texture\\JumpDownAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"JumpDownAttack", atlas, Vector2(0.0f, 0.0f), Vector2(200.0f / 4.0f, 79.0f), 4);
			//at->PlayAnimation(L"JumpDownAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"RunJumpDownAttck", L"..\\Resources\\Texture\\RunJumpDownAttack.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"RunJumpDownAttack", atlas, Vector2(0.0f, 0.0f), Vector2(372.0f / 6.0f, 82.0f), 6);
			//at->PlayAnimation(L"RunJumpDownAttack", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"JumpDownHit", L"..\\Resources\\Texture\\JumpDownHit.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"JumpDownHit", atlas, Vector2(0.0f, 0.0f), Vector2(329.0f / 7.0f, 76.0f), 7);
			//at->PlayAnimation(L"JumpDownHit", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"RoundKick", L"..\\Resources\\Texture\\RoundKick.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"RoundKick", atlas, Vector2(0.0f, 0.0f), Vector2(897.0f / 13.0f, 72.0f), 13);
			//at->PlayAnimation(L"RoundKick", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"FireBall", L"..\\Resources\\Texture\\FireBall.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"FireBall", atlas, Vector2(0.0f, 0.0f), Vector2(1144.0f / 13.0f, 70.0f), 13);
			//at->PlayAnimation(L"FireBall", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"NormalGlowCombo", L"..\\Resources\\Texture\\NormalGlowCombo.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"NormalGlowCombo", atlas, Vector2(0.0f, 0.0f), Vector2(434.0f / 7.0f, 71.0f), 7);
			//at->PlayAnimation(L"NormalGlowCombo", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"WeaponGlowCombo", L"..\\Resources\\Texture\\WeaponGlowCombo.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"WeaponGlowCombo", atlas, Vector2(0.0f, 0.0f), Vector2(839.0f / 10.0f, 84.0f), 10);
			//at->PlayAnimation(L"WeaponGlowCombo", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Counter", L"..\\Resources\\Texture\\Counter.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Counter", atlas, Vector2(0.0f, 0.0f), Vector2(1596.0f / 17.0f, 87.0f), 17);
			//at->PlayAnimation(L"Counter", true);

			//std::shared_ptr<Texture> atlas
			//	= Resources::Load<Texture>(L"Super", L"..\\Resources\\Texture\\Super.png");
			//Animator* at = player->AddComponent<Animator>();
			//at->Create(L"Super", atlas, Vector2(0.0f, 0.0f), Vector2(3913.0f / 31.0f, 126.0f), 31);
			//at->PlayAnimation(L"Super", true);




				
			//at->CompleteEvent(L"Idle") = std::bind();

			//at->PlayAnimation(L"Run", true);
			player->AddComponent<PlayerScript>();
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