#include "yaRamonaScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"

namespace ya
{
	RamonaScript::RamonaScript()
	{

	}

	RamonaScript::~RamonaScript()
	{

	}

	void RamonaScript::Initialize()
	{
		std::shared_ptr<Texture> atlas
			= Resources::Load<Texture>(L"Idle", L"..\\Resources\\TEXTURE\\RAMONA\\Idle.png");
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"R_Idle", atlas, enums::eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(151.0f / 5.0f, 65.0f), 5);
		at->Create(L"L_Idle", atlas, enums::eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(151.0f / 5.0f, 65.0f), 5);

		atlas
			= Resources::Load<Texture>(L"Walk", L"..\\Resources\\TEXTURE\\RAMONA\\Walk.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"R_Walk", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(210.0f / 6.0f, 68.0f), 6);//, Vector2::Zero, 0.05f);
		at->Create(L"L_Walk", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(210.0f / 6.0f, 68.0f), 6);

		atlas
			= Resources::Load<Texture>(L"Run", L"..\\Resources\\TEXTURE\\RAMONA\\Run.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"R_Run", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(424.0f / 8.0f, 67.0f), 8);
		at->Create(L"L_Run", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(424.0f / 8.0f, 67.0f), 8);
		
		atlas
			= Resources::Load<Texture>(L"Jump", L"..\\Resources\\TEXTURE\\RAMONA\\Jump.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"R_Jump", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(432.0f / 9.0f, 78.0f), 9);
		at->Create(L"L_Jump", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(432.0f / 9.0f, 78.0f), 9);

		atlas
			= Resources::Load<Texture>(L"DJump", L"..\\Resources\\TEXTURE\\RAMONA\\DJumpEdited.png");
		at = this->GetOwner()->GetComponent<Animator>();
		//at->Create(L"R_DJump", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(309.0f / 6.0f, 75.0f), 6);
		//at->Create(L"L_DJump", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(309.0f / 6.0f, 75.0f), 6);
		at->Create(L"R_DJump", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(757.0f / 12.0f, 63.0f), 12);
		at->Create(L"L_DJump", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(757.0f / 12.0f, 63.0f), 12);

		atlas
			= Resources::Load<Texture>(L"NormalAttack", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"NormalAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);

		atlas
			= Resources::Load<Texture>(L"Kick", L"..\\Resources\\TEXTURE\\RAMONA\\Kick.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Kick", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(310.0f / 5.0f, 70.0f), 5);

		atlas
			= Resources::Load<Texture>(L"RoundKick", L"..\\Resources\\TEXTURE\\RAMONA\\RoundKick.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"RoundKick", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(897.0f / 13.0f, 72.0f), 13);

		atlas
			= Resources::Load<Texture>(L"Guard", L"..\\Resources\\TEXTURE\\RAMONA\\Guard.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Guard", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(219.0f / 5.0f, 70.0f), 5);

		atlas
			= Resources::Load<Texture>(L"Evade", L"..\\Resources\\TEXTURE\\RAMONA\\Evade.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Evade", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(399.0f / 7.0f, 64.0f), 7);

		atlas
			= Resources::Load<Texture>(L"Super", L"..\\Resources\\TEXTURE\\RAMONA\\Super.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Super", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(3913.0f / 31.0f, 126.0f), 31);


		#pragma region Animation Path, Size
		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Walk", L"..\\Resources\\TEXTURE\\RAMONA\\Walk.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Walk", atlas, Vector2(0.0f, 0.0f), Vector2(210.0f / 6.0f, 68.0f), 6);
		//at->PlayAnimation(L"Walk", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Run", L"..\\Resources\\TEXTURE\\RAMONA\\Run.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Run", atlas, Vector2(0.0f, 0.0f), Vector2(424.0f / 8.0f, 67.0f), 8);
		//at->PlayAnimation(L"Run", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Jump", L"..\\Resources\\TEXTURE\\RAMONA\\Jump.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Jump", atlas, Vector2(0.0f, 0.0f), Vector2(432.0f / 9.0f, 78.0f), 9);
		//at->PlayAnimation(L"Jump", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"DJump", L"..\\Resources\\TEXTURE\\RAMONA\\DJump.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"DJump", atlas, Vector2(0.0f, 0.0f), Vector2(309.0f / 6.0f, 75.0f), 6);
		//at->PlayAnimation(L"DJump", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Guard", L"..\\Resources\\TEXTURE\\RAMONA\\Guard.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Guard", atlas, Vector2(0.0f, 0.0f), Vector2(219.0f / 5.0f, 70.0f), 5);
		//at->PlayAnimation(L"Guard", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Evade", L"..\\Resources\\TEXTURE\\RAMONA\\Evade.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Evade", atlas, Vector2(0.0f, 0.0f), Vector2(399.0f / 7.0f, 64.0f), 7);
		//at->PlayAnimation(L"Evade", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Downed", L"..\\Resources\\TEXTURE\\RAMONA\\Downed.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Downed", atlas, Vector2(0.0f, 0.0f), Vector2(292.0f / 4.0f, 69.0f), 4);
		//at->PlayAnimation(L"Downed", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Held", L"..\\Resources\\TEXTURE\\RAMONA\\Held_.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Held", atlas, Vector2(0.0f, 0.0f), Vector2(106.0f / 2.0f, 64.0f), 2);
		//at->PlayAnimation(L"Held", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Behind", L"..\\Resources\\TEXTURE\\RAMONA\\Behind.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Behind", atlas, Vector2(0.0f, 0.0f), Vector2(150.0f / 3.0f, 69.0f), 3);
		//at->PlayAnimation(L"Behind", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Front", L"..\\Resources\\TEXTURE\\RAMONA\\Front.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Front", atlas, Vector2(0.0f, 0.0f), Vector2(192.0f / 4.0f, 70.0f), 4);
		//at->PlayAnimation(L"Front", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Stun", L"..\\Resources\\TEXTURE\\RAMONA\\Stun.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Stun", atlas, Vector2(0.0f, 0.0f), Vector2(92.0f / 2.0f, 66.0f), 2);
		//at->PlayAnimation(L"Stun", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"KnockDown", L"..\\Resources\\TEXTURE\\RAMONA\\KnockDown.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"KnockDown", atlas, Vector2(0.0f, 0.0f), Vector2(988.0f / 13.0f, 88.0f), 13);
		//at->PlayAnimation(L"KnockDown", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Revived", L"..\\Resources\\TEXTURE\\RAMONA\\Revived.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Revived", atlas, Vector2(0.0f, 0.0f), Vector2(592.0f / 8.0f, 160.0f), 8);
		//at->PlayAnimation(L"Revived", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"GetUp", L"..\\Resources\\TEXTURE\\RAMONA\\GetUp.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"GetUp", atlas, Vector2(0.0f, 0.0f), Vector2(675.0f / 9.0f, 86.0f), 9);
		//at->PlayAnimation(L"GetUp", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"StageClear", L"..\\Resources\\TEXTURE\\RAMONA\\StageClear.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"StageClear", atlas, Vector2(0.0f, 0.0f), Vector2(364.0f / 7.0f, 83.0f), 7);
		//at->PlayAnimation(L"StageClear", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"StageExit", L"..\\Resources\\TEXTURE\\RAMONA\\StageExit.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"StageExit", atlas, Vector2(0.0f, 0.0f), Vector2(986.0f / 21.0f, 78.0f), 21);
		//at->PlayAnimation(L"StageExit", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"NormalAttack1", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"NormalAttack", atlas, Vector2(0.0f, 0.0f), Vector2(558.0f / 9.0f, 70.0f), 9);
		//at->PlayAnimation(L"NormalAttack", true);

		//// 공격 1,2,3 1애니메이션 진행중에 공격키 누르면 2 진행, 2 진행중에 공격키 누르면 3진행
		//std::shared_ptr<Texture> atlas
		//= Resources::Load<Texture>(L"NormalAttack1", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack1.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"NormalAttack1", atlas, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);
		//at->PlayAnimation(L"NormalAttack1", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"NormalAttack2", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack2.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"NormalAttack2", atlas, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);
		//at->PlayAnimation(L"NormalAttack2", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"NormalAttack3", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack3.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"NormalAttack3", atlas, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);
		//at->PlayAnimation(L"NormalAttack3", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Kick", L"..\\Resources\\TEXTURE\\RAMONA\\Kick.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Kick", atlas, Vector2(0.0f, 0.0f), Vector2(310.0f / 5.0f, 70.0f), 5);
		//at->PlayAnimation(L"Kick", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"NormalWeaponAttack", L"..\\Resources\\TEXTURE\\RAMONA\\NormalWeaponAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"NormalWeaponAttack", atlas, Vector2(0.0f, 0.0f), Vector2(663.0f / 8.0f, 86.0f), 8);
		//at->PlayAnimation(L"NormalWeaponAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"RunSlideAttack", L"..\\Resources\\TEXTURE\\RAMONA\\RunSlideAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"RunSlideAttack", atlas, Vector2(0.0f, 0.0f), Vector2(328.0f / 5.0f, 66.0f), 5);
		//at->PlayAnimation(L"RunSlideAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"RunWeaponAttack", L"..\\Resources\\TEXTURE\\RAMONA\\RunWeaponAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"RunWeaponAttack", atlas, Vector2(0.0f, 0.0f), Vector2(752.0f / 8.0f, 70.0f), 8);
		//at->PlayAnimation(L"RunWeaponAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"BehindAttack", L"..\\Resources\\TEXTURE\\RAMONA\\BehindAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"BehindAttack", atlas, Vector2(0.0f, 0.0f), Vector2(240.0f / 6.0f, 69.0f), 6);
		//at->PlayAnimation(L"BehindAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"WeaponStabAttack", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponStabAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"WeaponStabAttack", atlas, Vector2(0.0f, 0.0f), Vector2(394.0f / 5.0f, 71.0f), 5);
		//at->PlayAnimation(L"WeaponStabAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"WeaponDownAttack", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponDownAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"WeaponDownAttack", atlas, Vector2(0.0f, 0.0f), Vector2(255.0f / 5.0f, 75.0f), 5);
		//at->PlayAnimation(L"WeaponDownAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"JumpSlideAttack", L"..\\Resources\\TEXTURE\\RAMONA\\JumpSlideAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"JumpSlideAttack", atlas, Vector2(0.0f, 0.0f), Vector2(384.0f / 6.0f, 68.0f), 6);
		//at->PlayAnimation(L"JumpSlideAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"RunJumpAttack", L"..\\Resources\\TEXTURE\\RAMONA\\RunJumpAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"RunJumpAttack", atlas, Vector2(0.0f, 0.0f), Vector2(581.0f / 7.0f, 89.0f), 7);
		//at->PlayAnimation(L"RunJumpAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"WeaponLand", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponLand.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"WeaponLand", atlas, Vector2(0.0f, 0.0f), Vector2(612.0f / 9.0f, 78.0f), 9);
		//at->PlayAnimation(L"WeaponLand", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"WeaponSideAttack", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponSideAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"WeaponSideAttack", atlas, Vector2(0.0f, 0.0f), Vector2(805.0f / 8.0f, 79.0f), 8);
		//at->PlayAnimation(L"WeaponSideAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"JumpDownAttack", L"..\\Resources\\TEXTURE\\RAMONA\\JumpDownAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"JumpDownAttack", atlas, Vector2(0.0f, 0.0f), Vector2(200.0f / 4.0f, 79.0f), 4);
		//at->PlayAnimation(L"JumpDownAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"RunJumpDownAttck", L"..\\Resources\\TEXTURE\\RAMONA\\RunJumpDownAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"RunJumpDownAttack", atlas, Vector2(0.0f, 0.0f), Vector2(372.0f / 6.0f, 82.0f), 6);
		//at->PlayAnimation(L"RunJumpDownAttack", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"JumpDownHit", L"..\\Resources\\TEXTURE\\RAMONA\\JumpDownHit.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"JumpDownHit", atlas, Vector2(0.0f, 0.0f), Vector2(329.0f / 7.0f, 76.0f), 7);
		//at->PlayAnimation(L"JumpDownHit", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"RoundKick", L"..\\Resources\\TEXTURE\\RAMONA\\RoundKick.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"RoundKick", atlas, Vector2(0.0f, 0.0f), Vector2(897.0f / 13.0f, 72.0f), 13);
		//at->PlayAnimation(L"RoundKick", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"FireBall", L"..\\Resources\\TEXTURE\\RAMONA\\FireBall.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"FireBall", atlas, Vector2(0.0f, 0.0f), Vector2(1144.0f / 13.0f, 70.0f), 13);
		//at->PlayAnimation(L"FireBall", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"NormalGlowCombo", L"..\\Resources\\TEXTURE\\RAMONA\\NormalGlowCombo.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"NormalGlowCombo", atlas, Vector2(0.0f, 0.0f), Vector2(434.0f / 7.0f, 71.0f), 7);
		//at->PlayAnimation(L"NormalGlowCombo", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"WeaponGlowCombo", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponGlowCombo.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"WeaponGlowCombo", atlas, Vector2(0.0f, 0.0f), Vector2(839.0f / 10.0f, 84.0f), 10);
		//at->PlayAnimation(L"WeaponGlowCombo", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Counter", L"..\\Resources\\TEXTURE\\RAMONA\\Counter.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Counter", atlas, Vector2(0.0f, 0.0f), Vector2(1596.0f / 17.0f, 87.0f), 17);
		//at->PlayAnimation(L"Counter", true);

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"Super", L"..\\Resources\\TEXTURE\\RAMONA\\Super.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Super", atlas, Vector2(0.0f, 0.0f), Vector2(3913.0f / 31.0f, 126.0f), 31);
		//at->PlayAnimation(L"Super", true);
		#pragma endregion

		/// <summary>
		///
		/// </summary>
		at = GetOwner()->GetComponent<Animator>();

		//at->StartEvent(L"L_Jump") = std::bind(&RamonaScript::JumpStart, this);
		//at->StartEvent(L"R_Jump") = std::bind(&RamonaScript::JumpStart, this);

		at->CompleteEvent(L"L_Jump") = std::bind(&RamonaScript::JumpComplete, this);
		at->CompleteEvent(L"R_Jump") = std::bind(&RamonaScript::JumpComplete, this);

		//at->CompleteEvent(L"L_DJump") = std::bind(&RamonaScript::JumpComplete, this);
		//at->CompleteEvent(L"R_DJump") = std::bind(&RamonaScript::JumpComplete, this);

		at->CompleteEvent(L"Super") = std::bind(&RamonaScript::SuperComplete, this);
	}

	void RamonaScript::Update()
	{
		if (mPreviousState != mState)
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();

			switch (mState)
			{

			case ePlayerState::L_Idle:
				L_idle();
				break;
			case ePlayerState::R_Idle:
				R_idle();
				break;

			case ePlayerState::L_Walk:
				L_walk();
				break;
			case ePlayerState::R_Walk:
				R_walk();
				break;

			case ePlayerState::L_Run:
				L_run();
				break;
			case ePlayerState::R_Run:
				R_run();
				break;
			
			case ePlayerState::L_Jump:
				L_jump();
				break;
			case ePlayerState::R_Jump:
				R_jump();
				break;
			case ePlayerState::L_DJump:
				L_djump();
				break;
			case ePlayerState::R_DJump:
				R_djump();
				break;
			}
		}

		mPreviousState = mState;// 이전 상태 설정
		// 여기 아래에서부터 상태 변화가 진행되어야
		// 다음번 Update 부분으로 들어올 때, mState의 switch문 조건인
		// 이전 상태와 현재 상태가 다른 것을 통과하게 됨

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		//////////////////////////////////////////////////////////////////// 좌우 이동
		if (Input::GetKey(eKeyCode::LEFT))// 좌표 지속 이동
		{
			mDirection = eDirection::L;

			if(mIsJump == false)// Walk 애니메이션이 동작되어서는 안되는 상황: 점프
			mState = ePlayerState::L_Walk;

			pos.x -= 1.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKeyDown(eKeyCode::LEFT))
		{
			mDirection = eDirection::L;

			if (mIsJump == false)
			mState = ePlayerState::L_Walk;
		}

		if (Input::GetKeyUp(eKeyCode::LEFT))// 키 입력이 끝나고 이동하지 않을 때, Idle 상태로 전환
		{
			mDirection = eDirection::L;

			if (mIsJump == false)
			mState = ePlayerState::L_Idle;
		}

		if (Input::GetKey(eKeyCode::RIGHT))// 좌표 지속 이동
		{
			mDirection = eDirection::R;

			if (mIsJump == false)
			mState = ePlayerState::R_Walk;

			pos.x += 1.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKeyDown(eKeyCode::RIGHT))
		{
			mDirection = eDirection::R;

			if (mIsJump == false)
			mState = ePlayerState::R_Walk;
		}

		if (Input::GetKeyUp(eKeyCode::RIGHT))// 키 입력이 끝나고 이동하지 않을 때, Idle 상태로 전환
		{
			mDirection = eDirection::R;

			if (mIsJump == false)
			mState = ePlayerState::R_Idle;
		}


		//////////////////////////////////////////////////////////////////// 상하 이동
		if (Input::GetKey(eKeyCode::DOWN))
		{
			if (mIsJump == false && mState != ePlayerState::L_Jump && mState != ePlayerState::R_Jump
				&& mState != ePlayerState::L_DJump && mState != ePlayerState::R_DJump)// 점프나 더블점프 중에는 상하이동을 못하도록 막음
			{
				pos.y -= 1.0f * Time::DeltaTime();
				tr->SetPosition(pos);

				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_Walk;
				}
				else
				{
					mState = ePlayerState::R_Walk;
				}
			}
		}
		if (Input::GetKeyDown(eKeyCode::DOWN))
		{
			if (mIsJump == false && mState != ePlayerState::L_Jump && mState != ePlayerState::R_Jump
				&& mState != ePlayerState::L_DJump && mState != ePlayerState::R_DJump)
			{
				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_Walk;
				}
				else
				{
					mState = ePlayerState::R_Walk;
				}
			}
		}
		if (Input::GetKeyUp(eKeyCode::DOWN))// 키 입력이 끝나고 이동하지 않을 때, Idle 상태로 전환
		{
			if (mIsJump == false && mState != ePlayerState::L_Jump && mState != ePlayerState::R_Jump
				&& mState != ePlayerState::L_DJump && mState != ePlayerState::R_DJump)
			{
				if (!(Input::GetKey(eKeyCode::LEFT) || Input::GetKey(eKeyCode::RIGHT)))// 좌우키 입력이 있는 상태라면 Idle 상태로 전환시킬 필요가 없음
				{
					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_Idle;
					}
					else
					{
						mState = ePlayerState::R_Idle;
					}
				}
			}
		}

		if (Input::GetKey(eKeyCode::UP))
		{
			if (mIsJump == false && mIsDJump == false)// 점프 상태라면 Walk 애니메이션이 동작되어서는 안됨
			{
				pos.y += 1.0f * Time::DeltaTime();
				tr->SetPosition(pos);

				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_Walk;
				}
				else
				{
					mState = ePlayerState::R_Walk;
				}
			}
		}
		if (Input::GetKeyDown(eKeyCode::UP))
		{
			if (mIsJump == false && mIsDJump == false)
			{
				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_Walk;
				}
				else
				{
					mState = ePlayerState::R_Walk;
				}
			}
		}
		if (Input::GetKeyUp(eKeyCode::UP))// 키 입력이 끝나고 이동하지 않을 때, Idle 상태로 전환
		{
			if (mIsJump == false && mIsDJump == false)
			{
				if (!(Input::GetKey(eKeyCode::LEFT) || Input::GetKey(eKeyCode::RIGHT)))// 좌우키 입력이 있는 상태라면 Idle 상태로 전환시킬 필요가 없음
				{
					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_Idle;
					}
					else
					{
						mState = ePlayerState::R_Idle;
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////// 달리기
		if (Input::GetKey(eKeyCode::LSHIFT))
		{
			if (mState == ePlayerState::L_Walk || mState == ePlayerState::R_Walk)
			{
				//mIsRun = true;

				if (mDirection == eDirection::L)
				{
					if (Input::GetKey(eKeyCode::UP))
					{
						pos.y += 0.5f * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else if (Input::GetKey(eKeyCode::DOWN))
					{
						pos.y -= 0.5f * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else
					{
						pos.x -= 0.5f * Time::DeltaTime();
						tr->SetPosition(pos);
					}

					mState = ePlayerState::L_Run;
				}
				else
				{
					if (Input::GetKey(eKeyCode::UP))
					{
						pos.y += 0.5f * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else if (Input::GetKey(eKeyCode::DOWN))
					{
						pos.y -= 0.5f * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else
					{
						pos.x += 0.5f * Time::DeltaTime();
						tr->SetPosition(pos);
					}

					mState = ePlayerState::R_Run;
				}
			}
		}

		if (Input::GetKeyUp(eKeyCode::LSHIFT))
		{
			if (mState == ePlayerState::L_Run || mState == ePlayerState::R_Run)
			{
				//mIsRun = false;

				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_Walk;
				}
				else
				{
					mState = ePlayerState::R_Walk;
				}
			}
		}

		//////////////////////////////////////////////////////////////////// 점프
		if (Input::GetKeyDown(eKeyCode::SPACE) && mIsDJump == false)
		{
			mIsJump = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_Jump;
			}
			else
			{
				mState = ePlayerState::R_Jump;
			}
		}

		if (mIsJump == true)
		{
			if (mJumpStartPosY == -100.0f)// 점프 애니메이션 첫 시작할 때만 불러오는 조건
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				mJumpStartPosY = pos.y;

				//if (Input::GetKey(eKeyCode::LSHIFT))
				//{
				//	mJumpHeight = 2.5f;
				//}
				//else
				//{
				//	mJumpHeight = 1.8f;
				//}
			}

			mJumpTime += Time::DeltaTime();// 점프 체공 시간

			if (mJumpTime < mJumpHalfTime)// 좌표 상승 구간
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				pos.y += mJumpHeight * Time::DeltaTime();
				tr->SetPosition(pos);

				if (Input::GetKey(eKeyCode::LSHIFT))// 달리기 키를 누른 상태에서 점프는 더 멀리 가도록 조정
				{
					if (mDirection == eDirection::L)
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x -= 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
					else
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x += 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
				}
			}
			else// 좌표 하락 구간
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				pos.y -= mJumpHeight * Time::DeltaTime();
				tr->SetPosition(pos);

				if (pos.y <= mJumpStartPosY)// 좌표 하락하다가 점프 시작한 y좌표 위치에 도달(점프를, 좌표를 멈춰야 함)
				{
					Transform* tr = GetOwner()->GetComponent<Transform>();
					Vector3 pos = tr->GetPosition();
					Vector3 tempPos = Vector3(0.0f, mJumpStartPosY, 0.0f);
					pos.y = tempPos.y;
					tr->SetPosition(pos);// 점프 시작 위치로 강제 이동

					// 점프 관련 변수 초기화
					mJumpStartPosY = -100.0f;
					mJumpTime = 0.0f;
					mIsJump = false;
					mIsDJump = false;

					// 점프 끝난 직후 이동이 있다면 mState가 알아서 바뀌지만
					// 점프 끝난 직후 이동이 없다면 mState를 아래와 같이 Jump에서 Idle로 전환 
					if (!Input::GetKey(eKeyCode::LEFT) || !Input::GetKey(eKeyCode::RIGHT))
					{
						if (mDirection == eDirection::L)
						{
							mState = ePlayerState::L_Idle;
						}
						else
						{
							mState = ePlayerState::R_Idle;
						}
					}
				}

				if (Input::GetKey(eKeyCode::LSHIFT))// 달리기 키를 누른 상태에서 점프는 더 멀리 가도록 조정
				{
					if (mDirection == eDirection::L)
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x -= 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
					else
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x += 1.2f * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
				}
			}

			if (Input::GetKeyDown(eKeyCode::SPACE) && mJumpTime > 0.01f)// 점프 중 더블 점프가 발동되는 조건
			{
				if (mIsDJump == false)
				{
					mIsDJump = true;
					mJumpTime = 0.0f;

					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_DJump;
					}
					else
					{
						mState = ePlayerState::R_DJump;
					}
				}
			}
		}

		// Normal Attack: J
		if (Input::GetKeyDown(eKeyCode::J))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"NormalAttack", false);
		}

		// Kick: K
		if (Input::GetKeyDown(eKeyCode::K))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Kick", false);
		}

		// Round Kick: L
		if (Input::GetKeyDown(eKeyCode::L))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"RoundKick", false);
		}

		// Guard: H
		if (Input::GetKeyDown(eKeyCode::H))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Guard", false);
		}

		// Evade: N
		if (Input::GetKeyDown(eKeyCode::N))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Evade", false);
			//at->PlayAnimation(L"Super", true);

			//Transform* tr = this->GetOwner()->GetComponent<Transform>();
			//Vector3 pos = tr->GetPosition();
			//pos.y += 1.0f;
			//tr->SetPosition(pos);
		}
	}

	void RamonaScript::JumpStart()
	{
	}

	void RamonaScript::JumpComplete()
	{
		/*mJumpTime = 0.0f;
		mIsJump = false;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Vector3 tempPos = Vector3(0.0f, mJumpStartPosY, 0.0f);
		pos.y = tempPos.y;
		tr->SetPosition(pos);
		mJumpStartPosY = 0.0f;

		if (!Input::GetKey(eKeyCode::LEFT) || !Input::GetKey(eKeyCode::RIGHT))
		{
			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_Idle;
			}
			else
			{
				mState = ePlayerState::R_Idle;
			}
		}*/
	}

	void RamonaScript::SuperComplete()
	{
		//Transform* tr = this->GetOwner()->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();
		//pos.y -= 1.0f;
		//tr->SetPosition(pos);

		//Complete();
	}

	void RamonaScript::OnCollisionEnter(Collider2D* other)
	{
		int a = 0;
	}
	void RamonaScript::OnCollisionStay(Collider2D* other)
	{
		int a = 0;
	}
	void RamonaScript::OnCollisionExit(Collider2D* other)
	{
		int a = 0;
	}
	void RamonaScript::L_idle()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Idle", true);
	}
	void RamonaScript::R_idle()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Idle", true);
	}
	void RamonaScript::L_walk()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Walk", true);
	}
	void RamonaScript::R_walk()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Walk", true);
	}
	void RamonaScript::L_run()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Run", true);
	}
	void RamonaScript::R_run()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Run", true);
	}
	void RamonaScript::L_jump()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Jump", true);
	}
	void RamonaScript::R_jump()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Jump", true);
	}
	void RamonaScript::L_djump()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_DJump", false);
	}
	void RamonaScript::R_djump()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_DJump", false);
	}
}
