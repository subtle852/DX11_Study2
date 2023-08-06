#include "yaRamonaScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaCollider2D.h"

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
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �ִϸ��̼�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		std::shared_ptr<Texture> atlas
			= Resources::Load<Texture>(L"Idle", L"..\\Resources\\TEXTURE\\RAMONA\\Idle.png");
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"R_Idle", atlas, enums::eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(151.0f / 5.0f, 65.0f), 5);
		at->Create(L"L_Idle", atlas, enums::eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(151.0f / 5.0f, 65.0f), 5);

		atlas
			= Resources::Load<Texture>(L"Walk", L"..\\Resources\\TEXTURE\\RAMONA\\Walk.png");
		at->Create(L"R_Walk", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(210.0f / 6.0f, 68.0f), 6);//, Vector2::Zero, 0.05f);
		at->Create(L"L_Walk", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(210.0f / 6.0f, 68.0f), 6);

		atlas
			= Resources::Load<Texture>(L"Run", L"..\\Resources\\TEXTURE\\RAMONA\\Run.png");
		at->Create(L"R_Run", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(424.0f / 8.0f, 67.0f), 8);
		at->Create(L"L_Run", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(424.0f / 8.0f, 67.0f), 8);
		
		atlas
			= Resources::Load<Texture>(L"Jump", L"..\\Resources\\TEXTURE\\RAMONA\\Jump.png");
		at->Create(L"R_Jump", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(432.0f / 9.0f, 78.0f), 9);
		at->Create(L"L_Jump", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(432.0f / 9.0f, 78.0f), 9);

		atlas
			= Resources::Load<Texture>(L"DJump", L"..\\Resources\\TEXTURE\\RAMONA\\DJumpEdited.png");
		//at->Create(L"R_DJump", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(309.0f / 6.0f, 75.0f), 6);
		//at->Create(L"L_DJump", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(309.0f / 6.0f, 75.0f), 6);
		at->Create(L"R_DJump", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(757.0f / 12.0f, 63.0f), 12);
		at->Create(L"L_DJump", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(757.0f / 12.0f, 63.0f), 12);

		atlas
			= Resources::Load<Texture>(L"Guard", L"..\\Resources\\TEXTURE\\RAMONA\\Guard_ING.png");
		at->Create(L"R_Guard", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(87.0f / 2.0f, 70.0f), 2);
		at->Create(L"L_Guard", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(87.0f / 2.0f, 70.0f), 2);

		atlas
			= Resources::Load<Texture>(L"Evade", L"..\\Resources\\TEXTURE\\RAMONA\\Evade.png");
		at->Create(L"R_Evade", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(399.0f / 7.0f, 64.0f), 7);
		at->Create(L"L_Evade", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(399.0f / 7.0f, 64.0f), 7);

		atlas
			= Resources::Load<Texture>(L"NormalAttack1", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack1.png");
		at->Create(L"R_NormalAttack1", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3, Vector2::Zero, 0.15f);

		atlas
			= Resources::Load<Texture>(L"NormalAttack1_L", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack1_L.png");
		at->Create(L"L_NormalAttack1", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3, Vector2::Zero, 0.15f);

		atlas
			= Resources::Load<Texture>(L"NormalAttack2", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack2.png");
		at->Create(L"R_NormalAttack2", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3, Vector2::Zero, 0.15f);

		atlas
			= Resources::Load<Texture>(L"NormalAttack2_L", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack2_L.png");
		at->Create(L"L_NormalAttack2", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3, Vector2::Zero, 0.15f);

		atlas
			= Resources::Load<Texture>(L"NormalAttack3", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack3.png");
		at->Create(L"R_NormalAttack3", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3, Vector2::Zero, 0.15f);

		atlas
			= Resources::Load<Texture>(L"NormalAttack3_L", L"..\\Resources\\TEXTURE\\RAMONA\\NormalAttack3_L.png");
		at->Create(L"L_NormalAttack3", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3, Vector2::Zero, 0.15f);

		atlas
			= Resources::Load<Texture>(L"Kick", L"..\\Resources\\TEXTURE\\RAMONA\\Kick.png");
		at->Create(L"R_Kick", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(310.0f / 5.0f, 70.0f), 5);
		at->Create(L"L_Kick", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(310.0f / 5.0f, 70.0f), 5);

		atlas
			= Resources::Load<Texture>(L"RoundKick", L"..\\Resources\\TEXTURE\\RAMONA\\RoundKick.png");
		at->Create(L"R_RoundKick", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(897.0f / 13.0f, 72.0f), 13, Vector2::Zero, 0.07f);
		at->Create(L"L_RoundKick", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(897.0f / 13.0f, 72.0f), 13, Vector2::Zero, 0.07f);

		atlas
			= Resources::Load<Texture>(L"BehindAttack", L"..\\Resources\\TEXTURE\\RAMONA\\BehindAttack.png");
		at->Create(L"R_BehindKick", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(240.0f / 6.0f, 69.0f), 6);
		at->Create(L"L_BehindKick", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(240.0f / 6.0f, 69.0f), 6);

		atlas
			= Resources::Load<Texture>(L"WeaponNormalAttack", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponNormalAttack.png");
		at->Create(L"R_WeaponNormalAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(663.0f / 8.0f, 86.0f), 8);
		at->Create(L"L_WeaponNormalAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(663.0f / 8.0f, 86.0f), 8);

		atlas
			= Resources::Load<Texture>(L"WeaponDownAttack", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponDownAttack.png");
		at->Create(L"R_WeaponDownAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(255.0f / 5.0f, 75.0f), 5);
		at->Create(L"L_WeaponDownAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(255.0f / 5.0f, 75.0f), 5);

		atlas
			= Resources::Load<Texture>(L"WeaponSideAttack", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponSideAttack.png");
		at->Create(L"R_WeaponSideAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(805.0f / 8.0f, 79.0f), 8);
		at->Create(L"L_WeaponSideAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(805.0f / 8.0f, 79.0f), 8);
		 
		atlas
			= Resources::Load<Texture>(L"WeaponStabAttack", L"..\\Resources\\TEXTURE\\RAMONA\\WeaponStabAttack.png");
		at->Create(L"R_WeaponStabAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(394.0f / 5.0f, 71.0f), 5);
		at->Create(L"L_WeaponStabAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(394.0f / 5.0f, 71.0f), 5);
		
		atlas
			= Resources::Load<Texture>(L"JumpDownAttack", L"..\\Resources\\TEXTURE\\RAMONA\\JumpDownAttack.png");
		at->Create(L"R_JumpDownAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(200.0f / 4.0f, 79.0f), 4, Vector2::Zero, 0.12f);
		atlas
			= Resources::Load<Texture>(L"JumpDownAttack_L", L"..\\Resources\\TEXTURE\\RAMONA\\JumpDownAttack_L.png");
		at->Create(L"L_JumpDownAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(200.0f / 4.0f, 79.0f), 4, Vector2::Zero, 0.12f);

		atlas
			= Resources::Load<Texture>(L"JumpSlideAttack", L"..\\Resources\\TEXTURE\\RAMONA\\JumpSlideAttack.png");
		at->Create(L"R_JumpSlideAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(384.0f / 6.0f, 68.0f), 6, Vector2::Zero, 0.09f);
		atlas
			= Resources::Load<Texture>(L"JumpSlideAttack_L", L"..\\Resources\\TEXTURE\\RAMONA\\JumpSlideAttack_L.png");
		at->Create(L"L_JumpSlideAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(384.0f / 6.0f, 68.0f), 6, Vector2::Zero, 0.09f);

		atlas
			= Resources::Load<Texture>(L"RunJumpAttack", L"..\\Resources\\TEXTURE\\RAMONA\\RunJumpAttack.png");
		at->Create(L"R_RunJumpAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(581.0f / 7.0f, 89.0f), 7, Vector2::Zero, 0.07f);
		atlas
			= Resources::Load<Texture>(L"RunJumpAttack_L", L"..\\Resources\\TEXTURE\\RAMONA\\RunJumpAttack_L.png");
		at->Create(L"L_RunJumpAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(581.0f / 7.0f, 89.0f), 7, Vector2::Zero, 0.07f);

		atlas
			= Resources::Load<Texture>(L"RunWeaponAttack", L"..\\Resources\\TEXTURE\\RAMONA\\RunWeaponAttack.png");
		at->Create(L"R_RunWeaponAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(752.0f / 8.0f, 70.0f), 8);
		at->Create(L"L_RunWeaponAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(752.0f / 8.0f, 70.0f), 8);
		
		atlas
			= Resources::Load<Texture>(L"RunSlideAttack", L"..\\Resources\\TEXTURE\\RAMONA\\RunSlideAttack.png");
		at->Create(L"R_RunSlideAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(328.0f / 5.0f, 66.0f), 5);
		atlas
			= Resources::Load<Texture>(L"RunSlideAttack_L", L"..\\Resources\\TEXTURE\\RAMONA\\RunSlideAttack_L.png");
		at->Create(L"L_RunSlideAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(328.0f / 5.0f, 66.0f), 5);

		atlas
			= Resources::Load<Texture>(L"Super", L"..\\Resources\\TEXTURE\\RAMONA\\Super.png");
		at->Create(L"R_Super", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(3913.0f / 31.0f, 126.0f), 31, Vector2::Zero, 0.06f);
		at->Create(L"L_Super", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(3913.0f / 31.0f, 126.0f), 31, Vector2::Zero, 0.06f);

		atlas
			= Resources::Load<Texture>(L"FireBall", L"..\\Resources\\TEXTURE\\RAMONA\\FireBall.png");
		at->Create(L"R_FireBall", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(1144.0f / 13.0f, 70.0f), 13);
		at->Create(L"L_FireBall", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(1144.0f / 13.0f, 70.0f), 13);

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

		//// ���� 1,2,3 1�ִϸ��̼� �����߿� ����Ű ������ 2 ����, 2 �����߿� ����Ű ������ 3����
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
		//	= Resources::Load<Texture>(L"WeaponNormalAttack", L"..\\Resources\\TEXTURE\\RAMONA\\NormalWeaponAttack.png");
		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"WeaponNormalAttack", atlas, Vector2(0.0f, 0.0f), Vector2(663.0f / 8.0f, 86.0f), 8);
		//at->PlayAnimation(L"WeaponNormalAttack", true);

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

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		                                                    // �̺�Ʈ
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		at = GetOwner()->GetComponent<Animator>();

		//at->StartEvent(L"L_Jump") = std::bind(&RamonaScript::JumpStart, this);
		//at->StartEvent(L"R_Jump") = std::bind(&RamonaScript::JumpStart, this);

		at->CompleteEvent(L"L_Evade") = std::bind(&RamonaScript::EvadeComplete, this);
		at->CompleteEvent(L"R_Evade") = std::bind(&RamonaScript::EvadeComplete, this);

		at->CompleteEvent(L"L_NormalAttack1") = std::bind(&RamonaScript::NormalAttackComplete, this);
		at->CompleteEvent(L"R_NormalAttack1") = std::bind(&RamonaScript::NormalAttackComplete, this);
		at->CompleteEvent(L"L_NormalAttack2") = std::bind(&RamonaScript::NormalAttackComplete, this);
		at->CompleteEvent(L"R_NormalAttack2") = std::bind(&RamonaScript::NormalAttackComplete, this);
		at->CompleteEvent(L"L_NormalAttack3") = std::bind(&RamonaScript::NormalAttackComplete, this);
		at->CompleteEvent(L"R_NormalAttack3") = std::bind(&RamonaScript::NormalAttackComplete, this);

		at->CompleteEvent(L"L_Kick") = std::bind(&RamonaScript::KickComplete, this);
		at->CompleteEvent(L"R_Kick") = std::bind(&RamonaScript::KickComplete, this);
		at->CompleteEvent(L"L_RoundKick") = std::bind(&RamonaScript::KickComplete, this);
		at->CompleteEvent(L"R_RoundKick") = std::bind(&RamonaScript::KickComplete, this);
		at->CompleteEvent(L"L_BehindKick") = std::bind(&RamonaScript::KickComplete, this);
		at->CompleteEvent(L"R_BehindKick") = std::bind(&RamonaScript::KickComplete, this);

		at->CompleteEvent(L"L_WeaponNormalAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);
		at->CompleteEvent(L"R_WeaponNormalAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);
		at->CompleteEvent(L"L_WeaponDownAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);
		at->CompleteEvent(L"R_WeaponDownAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);
		at->CompleteEvent(L"L_WeaponSideAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);
		at->CompleteEvent(L"R_WeaponSideAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);
		at->CompleteEvent(L"L_WeaponStabAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);
		at->CompleteEvent(L"R_WeaponStabAttack") = std::bind(&RamonaScript::WeaponAttackComplete, this);

		at->CompleteEvent(L"L_JumpDownAttack") = std::bind(&RamonaScript::JumpAttackComplete, this);
		at->CompleteEvent(L"R_JumpDownAttack") = std::bind(&RamonaScript::JumpAttackComplete, this);
		at->CompleteEvent(L"L_JumpSlideAttack") = std::bind(&RamonaScript::JumpAttackComplete, this);
		at->CompleteEvent(L"R_JumpSlideAttack") = std::bind(&RamonaScript::JumpAttackComplete, this);
		at->CompleteEvent(L"L_RunJumpAttack") = std::bind(&RamonaScript::JumpAttackComplete, this);
		at->CompleteEvent(L"R_RunJumpAttack") = std::bind(&RamonaScript::JumpAttackComplete, this);

		at->CompleteEvent(L"L_RunWeaponAttack") = std::bind(&RamonaScript::RunAttackComplete, this);
		at->CompleteEvent(L"R_RunWeaponAttack") = std::bind(&RamonaScript::RunAttackComplete, this);
		at->CompleteEvent(L"L_RunSlideAttack") = std::bind(&RamonaScript::RunAttackComplete, this);
		at->CompleteEvent(L"R_RunSlideAttack") = std::bind(&RamonaScript::RunAttackComplete, this);
		
		at->CompleteEvent(L"L_FireBall") = std::bind(&RamonaScript::FireBallComplete, this);
		at->CompleteEvent(L"R_FireBall") = std::bind(&RamonaScript::FireBallComplete, this);
		at->CompleteEvent(L"L_Super") = std::bind(&RamonaScript::SuperComplete, this);
		at->CompleteEvent(L"R_Super") = std::bind(&RamonaScript::SuperComplete, this);


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �ݶ��̴�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		mBodyCd = this->GetOwner()->AddComponent<Collider2D>();
		mBodyCd->SetSize(Vector2(0.2f, 0.2f));
		mBodyCd->SetCenter(Vector2(0.0f, 0.0f));
		mBodyCd->SetActivation(eColliderActivation::Active);

		mUpperCd = this->GetOwner()->AddComponent<Collider2D>();
		mUpperCd->SetSize(Vector2(0.2f, 0.1f));
		mUpperCd->SetCenter(Vector2(0.2f, 0.08f));
		mUpperCd->SetActivation(eColliderActivation::InActive);

		mLowerCd = this->GetOwner()->AddComponent<Collider2D>();
		mLowerCd->SetSize(Vector2(0.2f, 0.1f));
		mLowerCd->SetCenter(Vector2(0.2f, -0.2f));
		mLowerCd->SetActivation(eColliderActivation::InActive);

		mBothCd = this->GetOwner()->AddComponent<Collider2D>();
		mBothCd->SetSize(Vector2(0.2f, 0.3f));
		mBothCd->SetCenter(Vector2(0.3f, 0.0f));
		mBothCd->SetActivation(eColliderActivation::InActive);
	
		mBackCd = this->GetOwner()->AddComponent<Collider2D>();
		mBackCd->SetSize(Vector2(0.1f, 0.1f));
		mBackCd->SetCenter(Vector2(-0.3f, -0.2f));
		mBackCd->SetActivation(eColliderActivation::InActive);

		mAllCd = this->GetOwner()->AddComponent<Collider2D>();
		mAllCd->SetSize(Vector2(0.35f, 0.25f));
		mAllCd->SetCenter(Vector2(0.0f, -0.0f));
		mAllCd->SetActivation(eColliderActivation::InActive);
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

			case ePlayerState::L_Guard:
				L_guard();
				break;
			case ePlayerState::R_Guard:
				R_guard();
				break;

			case ePlayerState::L_Evade:
				L_evade();
				break;
			case ePlayerState::R_Evade:
				R_evade();
				break;

			case ePlayerState::L_NormalAttack1:
				L_normalattack1();
				break;
			case ePlayerState::R_NormalAttack1:
				R_normalattack1();
				break;
			case ePlayerState::L_NormalAttack2:
				L_normalattack2();
				break;
			case ePlayerState::R_NormalAttack2:
				R_normalattack2();
				break;
			case ePlayerState::L_NormalAttack3:
				L_normalattack3();
				break;
			case ePlayerState::R_NormalAttack3:
				R_normalattack3();
				break;

			case ePlayerState::R_Kick:
				R_kick();
				break;
			case ePlayerState::L_Kick:
				L_kick();
				break;
			case ePlayerState::R_RoundKick:
				R_roundkick();
				break;
			case ePlayerState::L_RoundKick:
				L_roundkick();
				break;
			case ePlayerState::R_BehindKick:
				R_behindkick();
				break;
			case ePlayerState::L_BehindKick:
				L_behindkick();
				break;

			case ePlayerState::R_WeaponNormalAttack:
				R_weaponnormalattack();
				break;
			case ePlayerState::L_WeaponNormalAttack:
				L_weaponnormalattack();
				break;
			case ePlayerState::R_WeaponDownAttack:
				R_weapondownattack();
				break;
			case ePlayerState::L_WeaponDownAttack:
				L_weapondownattack();
				break;
			case ePlayerState::R_WeaponSideAttack:
				R_weaponsideattack();
				break;
			case ePlayerState::L_WeaponSideAttack:
				L_weaponsideattack();
				break;
			case ePlayerState::R_WeaponStabAttack:
				R_weaponstabattack();
				break;
			case ePlayerState::L_WeaponStabAttack:
				L_weaponstabattack();
				break;

			case ePlayerState::R_JumpDownAttack:
				R_jumpdownattack();
				break;
			case ePlayerState::L_JumpDownAttack:
				L_jumpdownattack();
				break;
			case ePlayerState::R_JumpSlideAttack:
				R_jumpslideattack();
				break;
			case ePlayerState::L_JumpSlideAttack:
				L_jumpslideattack();
				break;
			case ePlayerState::R_RunJumpAttack:
				R_runjumpattack();
				break;
			case ePlayerState::L_RunJumpAttack:
				L_runjumpattack();
				break;

			case ePlayerState::R_RunWeaponAttack:
				R_runweaponattack();
				break;
			case ePlayerState::L_RunWeaponAttack:
				L_runweaponattack();
				break;
			case ePlayerState::R_RunSlideAttack:
				R_runslideattack();
				break;
			case ePlayerState::L_RunSlideAttack:
				L_runslideattack();
				break;

			case ePlayerState::R_FireBall:
				R_fireball();
				break;
			case ePlayerState::L_FireBall:
				L_fireball();
				break;
			case ePlayerState::R_Super:
				R_super();
				break;
			case ePlayerState::L_Super:
				L_super();
				break;
			}
		}

		mPreviousState = mState;// ���� ���� ����
		// ���� �Ʒ��������� ���� ��ȭ�� ����Ǿ��
		// ������ Update �κ����� ���� ��, mState�� switch�� ������
		// ���� ���¿� ���� ���¸� ���ؼ� �ٸ� ���, case�� ���� �۵��ϰ� ��

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �ݶ��̴�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (mDirection == eDirection::L)
		{
			//std::vector<Collider2D*> comps
			//	= this->GetOwner()->GetComponents<Collider2D>();

			//mUpperCd = comps[1];
			mUpperCd->SetCenter(Vector2(-0.2f, 0.08f));

			//mLowerCd = comps[2];
			mLowerCd->SetCenter(Vector2(-0.2f, -0.2f));

			//mBothCd = comps[3];
			mBothCd->SetCenter(Vector2(-0.3f, 0.0f));

			mBackCd->SetCenter(Vector2(0.3f, -0.2f));
		}
		else
		{
			//std::vector<Collider2D*> comps
			//	= this->GetOwner()->GetComponents<Collider2D>();

			//mUpperCd = comps[1];
			mUpperCd->SetCenter(Vector2(0.2f, 0.08f));

			//mLowerCd = comps[2];
			mLowerCd->SetCenter(Vector2(0.2f, -0.2f));

			//mBothCd = comps[3];
			mBothCd->SetCenter(Vector2(0.3f, 0.0f));

			mBackCd->SetCenter(Vector2(-0.3f, -0.2f));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ��ġ
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �¿� �̵�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Input::GetKey(eKeyCode::LEFT))// ��ǥ ���� �̵�
		{
			mDirection = eDirection::L;

			if (NoneAnimationCondition())
			{
				mState = ePlayerState::L_Walk;
			}

			if (CanMoveCondition())// �¿� ������ �������� �ʴ� ��ų���� Ȯ��
			{
				pos.x -= mWalkSpeed * Time::DeltaTime();
				tr->SetPosition(pos);
			}
		}

		if (Input::GetKeyDown(eKeyCode::LEFT))
		{
			mDirection = eDirection::L;

			if (NoneAnimationCondition())
				mState = ePlayerState::L_Walk;
		}

		if (Input::GetKeyUp(eKeyCode::LEFT))// Ű �Է��� ������ �̵����� ���� ��, Idle ���·� ��ȯ
		{
			mDirection = eDirection::L;

			if (NoneAnimationCondition())
				mState = ePlayerState::L_Idle;
		}

		if (Input::GetKey(eKeyCode::RIGHT))// ��ǥ ���� �̵�
		{
			mDirection = eDirection::R;

			if (NoneAnimationCondition())
				mState = ePlayerState::R_Walk;

			if (CanMoveCondition())// �¿� ������ �������� �ʴ� ��ų���� Ȯ��
			{
				pos.x += mWalkSpeed * Time::DeltaTime();
				tr->SetPosition(pos);
			}
		}

		if (Input::GetKeyDown(eKeyCode::RIGHT))
		{
			mDirection = eDirection::R;

			if (NoneAnimationCondition())
				mState = ePlayerState::R_Walk;
		}

		if (Input::GetKeyUp(eKeyCode::RIGHT))// Ű �Է��� ������ �̵����� ���� ��, Idle ���·� ��ȯ
		{
			mDirection = eDirection::R;

			if (NoneAnimationCondition())
				mState = ePlayerState::R_Idle;
		}


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ���� �̵�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Input::GetKey(eKeyCode::DOWN))
		{
			if (NoneAnimationCondition())
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

			if (CanMoveCondition())// ���� ������ �������� �ʴ� ��ų���� Ȯ��
			{
				pos.y -= mWalkSpeed * Time::DeltaTime();
				tr->SetPosition(pos);
			}
		}
		if (Input::GetKeyDown(eKeyCode::DOWN))
		{
			if (NoneAnimationCondition())
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
		if (Input::GetKeyUp(eKeyCode::DOWN))// Ű �Է��� ������ �̵����� ���� ��, Idle ���·� ��ȯ
		{
			if (NoneAnimationCondition())
			{
				if (!(Input::GetKey(eKeyCode::LEFT) || Input::GetKey(eKeyCode::RIGHT)))// �¿�Ű �Է��� �ִ� ���¶�� Idle ���·� ��ȯ��ų �ʿ䰡 ����
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
			if (NoneAnimationCondition())
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

			if (CanMoveCondition())// ���� ������ �������� �ʴ� ��ų���� Ȯ��
			{
				pos.y += mWalkSpeed * Time::DeltaTime();
				tr->SetPosition(pos);
			}
		}
		if (Input::GetKeyDown(eKeyCode::UP))
		{
			if (NoneAnimationCondition())
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
		if (Input::GetKeyUp(eKeyCode::UP))// Ű �Է��� ������ �̵����� ���� ��, Idle ���·� ��ȯ
		{
			if (NoneAnimationCondition())
			{
				if (!(Input::GetKey(eKeyCode::LEFT) || Input::GetKey(eKeyCode::RIGHT)))// �¿�Ű �Է��� �ִ� ���¶�� Idle ���·� ��ȯ��ų �ʿ䰡 ����
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

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �޸���
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Input::GetKey(eKeyCode::LSHIFT))
		{
			if (mState == ePlayerState::L_Walk || mState == ePlayerState::R_Walk)
			{
				mIsRun = true;

				if (mDirection == eDirection::L)
				{
					if (Input::GetKey(eKeyCode::UP))
					{
						pos.y += mRunSpeed2 * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else if (Input::GetKey(eKeyCode::DOWN))
					{
						pos.y -= mRunSpeed2 * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else
					{
						pos.x -= mRunSpeed1 * Time::DeltaTime();
						tr->SetPosition(pos);
					}

					mState = ePlayerState::L_Run;
				}
				else
				{
					if (Input::GetKey(eKeyCode::UP))
					{
						pos.y += mRunSpeed2 * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else if (Input::GetKey(eKeyCode::DOWN))
					{
						pos.y -= mRunSpeed2 * Time::DeltaTime();
						tr->SetPosition(pos);
					}
					else
					{
						pos.x += mRunSpeed1 * Time::DeltaTime();
						tr->SetPosition(pos);
					}

					mState = ePlayerState::R_Run;
				}
			}
		}

		if (Input::GetKeyUp(eKeyCode::LSHIFT))
		{
			mIsRun = false;

			if (mState == ePlayerState::L_Run || mState == ePlayerState::R_Run )
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

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ����
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Input::GetKeyDown(eKeyCode::SPACE) && CanJumpCondition())
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
			if (mJumpStartPosY == -100.0f)// ���� �ִϸ��̼� ù ������ ���� �ҷ����� ����
			{
				// ���� ���� ��� ���� ������ �ʱ�ȭ�� ���� ���� ����
				mIsJumpDownAttack = false;
				mIsJumpSlideAttack = false;
				mIsRunJumpAttack = false;

				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				mJumpStartPosY = pos.y;

				if (Input::GetKey(eKeyCode::LSHIFT))// �޸� ��, ���� ���� �� ���� ����
				{
					mJumpHeight = mDJumpHeight;
				}
				else// �޸��� ���� ��, ���� ���� ���� ��ġ�� ����
				{
					mJumpHeight = 1.8f;
				}
			}

			mJumpTime += Time::DeltaTime();// ���� ü�� �ð�

			if (mJumpTime < mJumpHalfTime)// ��ǥ ��� ����
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				pos.y += mJumpHeight * Time::DeltaTime();
				tr->SetPosition(pos);

				if (Input::GetKey(eKeyCode::LSHIFT))// �޸��� Ű�� ���� ���¿��� ������ �� �ָ� ������ ���� (��� �ϴ� ���)
				{
					mIsRun = true;

					if (mDirection == eDirection::L)
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x -= mRunSpeed1 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
					else
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x += mRunSpeed1 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
				}

				// JumpDownAttack: ���� �� + W (���� ���� ��, JumpDownHit �ִϸ��̼� ���� �� ���� ����)
				if (Input::GetKeyDown(eKeyCode::W) && mIsJumpDownAttack == false && CanAttackCondition())
				{
					mIsJumpDownAttack = true;

					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_JumpDownAttack;
					}
					else
					{
						mState = ePlayerState::R_JumpDownAttack;
					}
				}
				// JumpSlideAttack: ���� �� + E
				if (Input::GetKeyDown(eKeyCode::E) && mIsJumpSlideAttack == false && CanAttackCondition())
				{
					mIsJumpSlideAttack = true;

					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_JumpSlideAttack;
					}
					else
					{
						mState = ePlayerState::R_JumpSlideAttack;
					}
				}
				// JumpSlideAttack: ���� �� + D
				if (Input::GetKey(eKeyCode::LSHIFT) && Input::GetKeyDown(eKeyCode::D) && mIsJumpSlideAttack == false && CanAttackCondition())
				{
					mIsJumpSlideAttack = true;

					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_RunJumpAttack;
					}
					else
					{
						mState = ePlayerState::R_RunJumpAttack;
					}
				}
			}

			else// ��ǥ �϶� ����
			{
				Transform* tr = GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				pos.y -= mJumpHeight * Time::DeltaTime();
				tr->SetPosition(pos);

				if (pos.y <= mJumpStartPosY)// ��ǥ �϶��ϴٰ� ���� ������ y��ǥ ��ġ�� ����(������, ��ǥ�� ����� ��)
				{
					Transform* tr = GetOwner()->GetComponent<Transform>();
					Vector3 pos = tr->GetPosition();
					Vector3 tempPos = Vector3(0.0f, mJumpStartPosY, 0.0f);
					pos.y = tempPos.y;
					tr->SetPosition(pos);// ���� ���� ��ġ�� ���� �̵�

					// ���� ���� ���� �ʱ�ȭ
					mJumpStartPosY = -100.0f;
					mJumpTime = 0.0f;
					mIsJump = false;
					mIsDJump = false;

					// ���� ���� ����鵵 �����ϸ� �ʱ�ȭ ����� ��
					mIsJumpDownAttack = false;
					mIsJumpSlideAttack = false;
					mIsRunJumpAttack = false;

					// ���� ���� ���� �̵��� �ִٸ� mState�� �˾Ƽ� �ٲ�����
					// ���� ���� ���� �̵��� ���ٸ� mState�� �Ʒ��� ���� Jump���� Idle�� ��ȯ 
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

				if (Input::GetKey(eKeyCode::LSHIFT))// �޸��� Ű�� ���� ���¿��� ������ �� �ָ� ������ ���� (�϶��ϴ� ���)
				{
					mIsRun = true;

					if (mDirection == eDirection::L)
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x -= mRunSpeed1 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
					else
					{
						if (Input::GetKey(eKeyCode::UP))
						{
							pos.y += mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else if (Input::GetKey(eKeyCode::DOWN))
						{
							pos.y -= mRunSpeed2 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
						else
						{
							pos.x += mRunSpeed1 * Time::DeltaTime();
							tr->SetPosition(pos);
						}
					}
				}

				// JumpDownAttack: ���� �� + W (���� ���� ��, JumpDownHit �ִϸ��̼� ���� �� ���� ����)
				if (Input::GetKeyDown(eKeyCode::W) && mIsJumpDownAttack == false && mIsJump == true && mIsDJump == true && CanAttackCondition())
				{
					mIsJumpDownAttack = true;

					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_JumpDownAttack;
					}
					else
					{
						mState = ePlayerState::R_JumpDownAttack;
					}
				}
				// JumpSlideAttack: ���� �� + E
				if (Input::GetKeyDown(eKeyCode::E) && mIsJumpSlideAttack == false && mIsJump == true && mIsDJump == true && CanAttackCondition())
				{
					mIsJumpSlideAttack = true;

					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_JumpSlideAttack;
					}
					else
					{
						mState = ePlayerState::R_JumpSlideAttack;
					}
				}
				// JumpSlideAttack: ���� �� + D
				if (Input::GetKey(eKeyCode::LSHIFT) && Input::GetKeyDown(eKeyCode::D) && mIsJumpSlideAttack == false && mIsJump == true && mIsDJump == true && CanAttackCondition())
				{
					mIsJumpSlideAttack = true;

					if (mDirection == eDirection::L)
					{
						mState = ePlayerState::L_RunJumpAttack;
					}
					else
					{
						mState = ePlayerState::R_RunJumpAttack;
					}
				}
			}

			if (Input::GetKeyDown(eKeyCode::SPACE) && mJumpTime > 0.01f)// ���� �� ���� ������ �ߵ��Ǵ� ����
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

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ����
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Input::GetKey(eKeyCode::Q))
		{
			if (mState == ePlayerState::L_Idle || mState == ePlayerState::R_Idle || mState == ePlayerState::L_Walk || mState == ePlayerState::R_Walk)
			{
				mIsGuard = true;
				mBodyCd->SetActivation(eColliderActivation::InActive);

				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_Guard;
				}
				else
				{
					mState = ePlayerState::R_Guard;
				}
			}
		}
		if (Input::GetKeyUp(eKeyCode::Q) && mIsGuard == true)
		{
			mIsGuard = false;
			mBodyCd->SetActivation(eColliderActivation::Active);

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_Idle;
			}
			else
			{
				mState = ePlayerState::R_Idle;
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ȸ��
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Input::GetKeyDown(eKeyCode::F))
		{
			if (mIsJump == false && mIsDJump == false)
			{
				mIsEvade = true;

				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_Evade;
				}
				else
				{
					mState = ePlayerState::R_Evade;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ��Ÿ
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// ù��° ����
		if (Input::GetKeyDown(eKeyCode::W) && mIsNormalAttack3 == false && mIsJump == false && mIsDJump == false && CanAttackCondition())// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsNormalAttack1 = true;
			mIsNormalAttack2 = false;
			mIsNormalAttack3 = false;
			//mCanNormalAttack2 = false;
			//mCanNormalAttack3 = false;
			mNormalAttack2Time = 0.0f;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_NormalAttack1;
			}
			else
			{
				mState = ePlayerState::R_NormalAttack1;
			}
		}

		// ���� ���� 1 
		// ���� ���� ���� ���� ���� ���� ���� ��� �ʱ�ȭ
		if (mIsNormalAttack1 == false && mIsNormalAttack2 == false && mIsNormalAttack3 == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsNormalAttack1 = false;
			mIsNormalAttack2 = false;
			mIsNormalAttack3 = false;
			mCanNormalAttack2 = false;
			mCanNormalAttack3 = false;
			mNormalAttack2Time = 0.0f;
		}

		// ���� ���� 2
		// ���� ���� ���� ���� ���� ���� ���� ��� �ʱ�ȭ
		if (!(mState == ePlayerState::L_NormalAttack1 || mState == ePlayerState::R_NormalAttack1
			|| mState == ePlayerState::L_NormalAttack2 || mState == ePlayerState::R_NormalAttack2
			|| mState == ePlayerState::L_NormalAttack3 || mState == ePlayerState::R_NormalAttack3))
		{
			mIsNormalAttack1 = false;
			mIsNormalAttack2 = false;
			mIsNormalAttack3 = false;
			mCanNormalAttack2 = false;
			mCanNormalAttack3 = false;
			mNormalAttack2Time = 0.0f;
		}

		// �ι�° ���� ����
		if (Input::GetKeyUp(eKeyCode::W) && mIsNormalAttack1 == true && mIsNormalAttack2 == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mCanNormalAttack2 = true;
		}

		// �ι�° ����
		if (mCanNormalAttack2 == true && Input::GetKeyDown(eKeyCode::W) && mIsNormalAttack2 == false && mIsNormalAttack3 == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsNormalAttack1 = false;
			mIsNormalAttack2 = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_NormalAttack2;
			}
			else
			{
				mState = ePlayerState::R_NormalAttack2;
			}

		}

		// ����° ���� ������ ���� �ð� ����
		if (mIsNormalAttack2)
		{
			mNormalAttack2Time += Time::DeltaTime();
		}

		// ����° ���� ����
		if (Input::GetKeyUp(eKeyCode::W) && mIsNormalAttack1 == false && mIsNormalAttack2 == true && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			if (mNormalAttack2Time > 0.004f)// 2 ������ ������ڸ��� �ٷ� 3 ������ ������� �ʵ��� �ð� ���̸� �ǵ������� ����
			{
				mCanNormalAttack3 = true;
			}
		}

		// ����° ����
		if (mCanNormalAttack3 == true && Input::GetKeyDown(eKeyCode::W) && mIsNormalAttack3 == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsNormalAttack2 = false;
			mNormalAttack2Time = 0.0f;
			mIsNormalAttack3 = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_NormalAttack3;
			}
			else
			{
				mState = ePlayerState::R_NormalAttack3;
			}

		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ������
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// Kick: E
		if (Input::GetKeyDown(eKeyCode::E) && mIsKickAttack == false && mIsRoundKickAttack == false && mIsBehindKickAttack == false && mIsJump == false && mIsDJump == false && CanAttackCondition())// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsKickAttack = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_Kick;
			}
			else
			{
				mState = ePlayerState::R_Kick;
			}
		}
		// Kick ���� ����
		if (!(mState == ePlayerState::L_Kick || mState == ePlayerState::R_Kick))
		{
			mIsKickAttack = false;
		}

		// Round Kick: UP + E
		if (Input::GetKey(eKeyCode::UP) && Input::GetKeyDown(eKeyCode::E) && mIsRoundKickAttack == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsKickAttack = false;
			mIsRoundKickAttack = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_RoundKick;
			}
			else
			{
				mState = ePlayerState::R_RoundKick;
			}
		}
		// Round Kick ���� ����
		if (!(mState == ePlayerState::L_RoundKick || mState == ePlayerState::R_RoundKick))
		{
			mIsRoundKickAttack = false;
		}

		// Behind Kick: DOWN + E
		if (Input::GetKey(eKeyCode::DOWN) && Input::GetKeyDown(eKeyCode::E) && mIsBehindKickAttack == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsKickAttack = false;
			mIsBehindKickAttack = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_BehindKick;
			}
			else
			{
				mState = ePlayerState::R_BehindKick;
			}
		}
		// Behind Kick ���� ����
		if (!(mState == ePlayerState::L_BehindKick || mState == ePlayerState::R_BehindKick))
		{
			mIsBehindKickAttack = false;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ���� ����
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// WeaponNormalAttack: D
		if (Input::GetKeyDown(eKeyCode::D) && mIsWeaponNormalAttack == false && mIsWeaponDownAttack == false && mIsWeaponSideAttack == false && mIsWeaponStabAttack == false && mIsJump == false && mIsDJump == false && CanAttackCondition())// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsWeaponNormalAttack = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_WeaponNormalAttack;
			}
			else
			{
				mState = ePlayerState::R_WeaponNormalAttack;
			}
		}
		// WeaponNormalAttack ���� ����
		if (!(mState == ePlayerState::L_WeaponNormalAttack || mState == ePlayerState::R_WeaponNormalAttack))
		{
			mIsWeaponNormalAttack = false;
		}

		// WeaponDownAttack: DOWN + D 
		if (Input::GetKey(eKeyCode::DOWN) && Input::GetKeyDown(eKeyCode::D) && mIsWeaponDownAttack == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsWeaponNormalAttack = false;
			mIsWeaponDownAttack = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_WeaponDownAttack;
			}
			else
			{
				mState = ePlayerState::R_WeaponDownAttack;
			}
		}
		// WeaponDownAttack���� ����
		if (!(mState == ePlayerState::L_WeaponDownAttack || mState == ePlayerState::R_WeaponDownAttack))
		{
			mIsWeaponDownAttack = false;
		}

		// WeaponSideAttack:LEFT OR RIGHT + D
		if ((Input::GetKey(eKeyCode::LEFT) || Input::GetKey(eKeyCode::RIGHT)) && Input::GetKeyDown(eKeyCode::D) && mIsWeaponSideAttack == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsWeaponNormalAttack = false;
			mIsWeaponSideAttack = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_WeaponSideAttack;
			}
			else
			{
				mState = ePlayerState::R_WeaponSideAttack;
			}
		}
		// WeaponSideAttack ���� ����
		if (!(mState == ePlayerState::L_WeaponSideAttack || mState == ePlayerState::R_WeaponSideAttack))
		{
			mIsWeaponSideAttack = false;
		}

		// WeaponStabAttack: D + UP
		if (Input::GetKey(eKeyCode::UP) && Input::GetKeyDown(eKeyCode::D) && mIsWeaponStabAttack == false && mIsJump == false && mIsDJump == false)// ������ �������� �� Ű�Է��� �ٸ� ����� ������ ��
		{
			mIsWeaponNormalAttack = false;
			mIsWeaponStabAttack = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_WeaponStabAttack;
			}
			else
			{
				mState = ePlayerState::R_WeaponStabAttack;
			}
		}
		// WeaponStabAttack ���� ����
		if (!(mState == ePlayerState::L_WeaponStabAttack || mState == ePlayerState::R_WeaponStabAttack))
		{
			mIsWeaponStabAttack = false;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ���� �� ����
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// JumpDownAttack: ���� �� + W (���� ���� ��, JumpDownHit �ִϸ��̼� ���� �� ���� ����)
		// ���� �� ���� �� �κп� ������

		// JumpSlideAttack: ���� �� + E
		// ���� �� ���� �� �κп� ������

		// RunJumpAttack: SHIFT + ���� �� + D
		// ���� �� ���� �� �κп� ������
		
		// RunJumpDownAttack: SHIFT(�������� ���¿���) + ���� �� + E 
		// ���� ���� ����

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �޸��� �� ����
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// RunWeaponAttack: �޸��� ���¿��� + D
		if (mIsRun == true && mIsRunWeaponAttack == false && mIsJump == false && mIsDJump == false)
		{
			if (Input::GetKeyDown(eKeyCode::D) && mIsRunSlideAttack == false)
			{
				mIsRunWeaponAttack = true;
				
				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_RunWeaponAttack;
				}
				else
				{
					mState = ePlayerState::R_RunWeaponAttack;
				}
			}
		}

		// RunSlideAttack: �޸��� ���¿��� + E
		if (mIsRun == true && mIsRunSlideAttack == false && mIsJump == false && mIsDJump == false)
		{
			if (Input::GetKeyDown(eKeyCode::E) && mIsRunWeaponAttack == false)
			{
				mIsRunSlideAttack = true;

				if (mDirection == eDirection::L)
				{
					mState = ePlayerState::L_RunSlideAttack;
				}
				else
				{
					mState = ePlayerState::R_RunSlideAttack;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �ñر�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// FireBall: R (GP 50 ����)
		if (Input::GetKeyDown(eKeyCode::R) && NoneAnimationCondition() && CanAttackCondition())
		{
			//if (0.0f <= mAbilty.mGP && mAbilty.mGP <= 50.0f)
			//{

			//}

			mIsFireBall = true;

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_FireBall;
			}
			else
			{
				mState = ePlayerState::R_FireBall;
			}
		}
		 
		// Super: R (GP 50 �ʰ�)// R��ư�ε� GP ������ ���� �ʾƼ� �ϴ� TŰ�� �Է�
		//if (Input::GetKeyDown(eKeyCode::R) && mIsSuper == false && mIsJump == false && mIsDJump == false)
		//{
		//	if (mAbilty.mGP > 50.0f)
		//	{

		//	}
		//}
		if (Input::GetKeyDown(eKeyCode::T) && NoneAnimationCondition() && CanAttackCondition() && CanAttackCondition())
		{
			mIsSuper = true;

			//Transform* tr = this->GetOwner()->GetComponent<Transform>();
			//Vector3 pos = tr->GetPosition();
			//pos.y += 1.0f;
			//tr->SetPosition(pos);

			if (mDirection == eDirection::L)
			{
				mState = ePlayerState::L_Super;
			}
			else
			{
				mState = ePlayerState::R_Super;
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �߰��ؾ��� �κ�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		// Glow, Counter,...
		// �� ���´� Collider�� �߰��ϴ� �����۾��� �䱸
		// Collider �� ����? � ��ġ��? ��ġ���� ��� �� ����

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �ݶ��̴� & ��ų ����ȭ
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ������
		// Activation�� Set���� �����ϴ� ���� �Ϲ���
		// State�� Get���� �޾ƿ� �浹 ������ �ľ��ϴ� ���� �Ϲ���
		
		//  mIsNormalAttack1 U || mIsNormalAttack2 U || mIsNormalAttack3 U ||
		//	mIsKickAttack L|| mIsRoundKickAttack B || mIsBehindKickAttack Back||
		//	mIsWeaponNormalAttack B || mIsWeaponDownAttack L || mIsWeaponSideAttack B || mIsWeaponStabAttack L ||
		//	mIsJumpDownAttack L || mIsJumpSlideAttack L  || mIsRunJumpAttack L ||
		//	mIsRunWeaponAttack B || mIsRunSlideAttack L ||
		//	mIsFireBall B || mIsSuper A

		// Upper
		if (mIsNormalAttack1 || mIsNormalAttack2 || mIsNormalAttack3)
		{
			mUpperCd->SetActivation(eColliderActivation::Active);
		}
		else
		{
			mUpperCd->SetActivation(eColliderActivation::InActive);
		}

		// Lower
		if (mIsKickAttack || mIsWeaponDownAttack || mIsWeaponStabAttack 
			|| mIsJumpDownAttack || mIsJumpSlideAttack || mIsRunJumpAttack || mIsRunSlideAttack)
		{
			mLowerCd->SetActivation(eColliderActivation::Active);
		}
		else
		{
			mLowerCd->SetActivation(eColliderActivation::InActive);
		}

		// Both
		if (mIsRoundKickAttack || mIsWeaponNormalAttack || mIsWeaponSideAttack 
			|| mIsRunWeaponAttack || mIsFireBall)
		{

			mBothCd->SetActivation(eColliderActivation::Active);
		}
		else
		{
			mBothCd->SetActivation(eColliderActivation::InActive);
		}

		// Back
		if (mIsBehindKickAttack)
		{
			mBackCd->SetActivation(eColliderActivation::Active);
		}
		else
		{
			mBackCd->SetActivation(eColliderActivation::InActive);
		}

		// All
		if (mIsSuper)
		{
			mAllCd->SetActivation(eColliderActivation::Active);
		}
		else
		{
			mAllCd->SetActivation(eColliderActivation::InActive);
		}


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ��ų ���� Update
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		mAttackState[0] = mIsNormalAttack1;
		mAttackState[1] = mIsNormalAttack2;
		mAttackState[2] = mIsNormalAttack3;
		mAttackState[3] = mIsKickAttack;
		mAttackState[4] = mIsRoundKickAttack;
		mAttackState[5] = mIsBehindKickAttack;
		mAttackState[6] = mIsWeaponNormalAttack;
		mAttackState[7] = mIsWeaponDownAttack;
		mAttackState[8] = mIsWeaponSideAttack;
		mAttackState[9] = mIsWeaponStabAttack;
		mAttackState[10] = mIsJumpDownAttack;
		mAttackState[11] = mIsJumpSlideAttack;
		mAttackState[12] = mIsRunJumpAttack;
		mAttackState[13] = mIsRunWeaponAttack;
		mAttackState[14] = mIsRunSlideAttack;
		mAttackState[15] = mIsFireBall;
		mAttackState[16] = mIsSuper;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �̺�Ʈ �Լ�
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void RamonaScript::EvadeComplete()
	{
		mIsEvade = false;

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	void RamonaScript::NormalAttackComplete()
	{
		if (mIsNormalAttack1 == true)
		{
			mIsNormalAttack1 = false;

			mCanNormalAttack2 = false;
			mCanNormalAttack3 = false;
		}

		if (mIsNormalAttack2 == true)
		{
			mIsNormalAttack2 = false;

			mCanNormalAttack2 = false;
			mCanNormalAttack3 = false;
		}

		if (mIsNormalAttack3 == true)
		{
			mIsNormalAttack3 = false;

			mCanNormalAttack2 = false;
			mCanNormalAttack3 = false;
			mNormalAttack2Time = 0.0f;
		}

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	void RamonaScript::KickComplete()
	{
		mIsKickAttack = false;
		mIsRoundKickAttack = false;
		mIsBehindKickAttack = false;

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	void RamonaScript::WeaponAttackComplete()
	{
		mIsWeaponNormalAttack = false;
		mIsWeaponDownAttack = false;
		mIsWeaponSideAttack = false;
		mIsWeaponStabAttack = false;

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	void RamonaScript::JumpAttackComplete()
	{
		mIsJumpDownAttack = false;
		mIsJumpSlideAttack = false;
		mIsRunJumpAttack = false;

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	void RamonaScript::RunAttackComplete()
	{
		mIsRunWeaponAttack = false;
		mIsRunSlideAttack = false;

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	void RamonaScript::FireBallComplete()
	{
		mIsFireBall = false;

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	void RamonaScript::SuperComplete()
	{
		mIsSuper = false;

		//Transform* tr = this->GetOwner()->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();
		//pos.y -= 1.0f;
		//tr->SetPosition(pos);

		if (mDirection == eDirection::L)
		{
			mState = ePlayerState::L_Idle;
		}
		else
		{
			mState = ePlayerState::R_Idle;
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �浹
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ��Ÿ �Լ�
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// �ִϸ��̼��� ���۵Ǿ�� �ȵǴ� ��Ȳ: 
	// ex. ���� �� ���� Ű�� �����ٰ� �ؼ� R_Walk�� ����Ǹ� �ȵ�
	bool RamonaScript::NoneAnimationCondition()
	{
		if (
				mIsJump == false && mIsEvade == false // mIsDJump�� ��¥�� mIsJump�� true�� ���¿����� ����Ǳ⿡ ���� ����
				&& mIsNormalAttack1 == false && mIsNormalAttack2 == false && mIsNormalAttack3 == false
				&& mIsKickAttack == false && mIsRoundKickAttack == false && mIsBehindKickAttack == false
				&& mIsWeaponNormalAttack == false && mIsWeaponDownAttack == false && mIsWeaponSideAttack == false && mIsWeaponStabAttack == false
				&& mIsJumpDownAttack == false && mIsJumpSlideAttack == false
				&& mIsRunWeaponAttack == false && mIsRunSlideAttack == false
				&& mIsFireBall == false && mIsSuper == false
			)
			return true;

		return false;
	}

	// �¿� ���� �̵��� ���ƾ��ϴ� ��Ȳ
	bool RamonaScript::CanMoveCondition()
	{
		if (
				mIsGuard == true
				|| mIsNormalAttack1 == true || mIsNormalAttack2 == true || mIsNormalAttack3 == true
				|| mIsKickAttack == true || mIsRoundKickAttack == true || mIsBehindKickAttack == true
				|| mIsWeaponNormalAttack == true || mIsWeaponDownAttack == true || mIsWeaponSideAttack == true || mIsWeaponStabAttack == true
				|| mIsFireBall == true
			)
		{
			return false;
		}

		return true;
	}

	bool RamonaScript::CanJumpCondition()
	{
		if (
				mIsJump == false && mIsDJump == false
				&& mIsGuard == false && mIsEvade == false
				&& mIsNormalAttack1 == false && mIsNormalAttack2 == false && mIsNormalAttack3 == false
				&& mIsKickAttack == false && mIsRoundKickAttack == false && mIsBehindKickAttack == false
				&& mIsWeaponNormalAttack == false && mIsWeaponDownAttack == false && mIsWeaponSideAttack == false && mIsWeaponStabAttack == false
				&& mIsRunWeaponAttack == false && mIsRunSlideAttack == false
				&& mIsFireBall == false && mIsSuper == false
			)
			return true;

		return false;
	}

	bool RamonaScript::CanAttackCondition()
	{
		if (
				mIsEvade == true
				|| mIsNormalAttack1 == true || mIsNormalAttack2 == true || mIsNormalAttack3 == true
				|| mIsKickAttack == true || mIsRoundKickAttack == true || mIsBehindKickAttack == true
				|| mIsWeaponNormalAttack == true || mIsWeaponDownAttack == true || mIsWeaponSideAttack == true || mIsWeaponStabAttack == true
				|| mIsJumpDownAttack == true || mIsJumpSlideAttack == true
				|| mIsRunWeaponAttack == true || mIsRunSlideAttack == true
				|| mIsFireBall == true || mIsSuper == true
			)
			return false;

		return true;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
														// ���� �ִϸ��̼� �Լ�
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	void RamonaScript::L_guard()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Guard", false);
	}
	void RamonaScript::R_guard()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Guard", false);
	}
	void RamonaScript::L_evade()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Evade", true);
	}
	void RamonaScript::R_evade()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Evade", true);
	}
	void RamonaScript::L_normalattack1()
	{
		mIsNormalAttack1 = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_NormalAttack1", true);
	}
	void RamonaScript::R_normalattack1()
	{
		mIsNormalAttack1 = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_NormalAttack1", true);
	}
	void RamonaScript::L_normalattack2()
	{
		mCanNormalAttack2 = false;
		mIsNormalAttack2 = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_NormalAttack2", true);
	}
	void RamonaScript::R_normalattack2()
	{
		mCanNormalAttack2 = false;
		mIsNormalAttack2 = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_NormalAttack2", true);
	}
	void RamonaScript::L_normalattack3()
	{
		mCanNormalAttack3 = false;
		mIsNormalAttack3 = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_NormalAttack3", true);
	}
	void RamonaScript::R_normalattack3()
	{
		mCanNormalAttack3 = false;
		mIsNormalAttack3 = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_NormalAttack3", true);
	}
	void RamonaScript::L_kick()
	{
		mIsKickAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Kick", true);
	}
	void RamonaScript::R_kick()
	{
		mIsKickAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Kick", true);
	}
	void RamonaScript::L_roundkick()
	{
		mIsRoundKickAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_RoundKick", true);
	}
	void RamonaScript::R_roundkick()
	{
		mIsRoundKickAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_RoundKick", true);
	}
	void RamonaScript::L_behindkick()
	{
		mIsBehindKickAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_BehindKick", true);
	}
	void RamonaScript::R_behindkick()
	{
		mIsBehindKickAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_BehindKick", true);
	}
	void RamonaScript::L_weaponnormalattack()
	{
		mIsWeaponNormalAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_WeaponNormalAttack", true);
	}
	void RamonaScript::R_weaponnormalattack()
	{
		mIsWeaponNormalAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_WeaponNormalAttack", true);
	}
	void RamonaScript::L_weapondownattack()
	{
		mIsWeaponDownAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_WeaponDownAttack", true);
	}
	void RamonaScript::R_weapondownattack()
	{
		mIsWeaponDownAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_WeaponDownAttack", true);
	}
	void RamonaScript::L_weaponsideattack()
	{
		mIsWeaponSideAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_WeaponSideAttack", true);
	}
	void RamonaScript::R_weaponsideattack()
	{
		mIsWeaponSideAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_WeaponSideAttack", true);
	}
	void RamonaScript::L_weaponstabattack()
	{
		mIsWeaponStabAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_WeaponStabAttack", true);
	}
	void RamonaScript::R_weaponstabattack()
	{
		mIsWeaponStabAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_WeaponStabAttack", true);
	}
	void RamonaScript::L_jumpdownattack()
	{
		mIsJumpDownAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_JumpDownAttack", true);
	}
	void RamonaScript::R_jumpdownattack()
	{
		mIsJumpDownAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_JumpDownAttack", true);
	}
	void RamonaScript::L_jumpslideattack()
	{
		mIsJumpSlideAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_JumpSlideAttack", true);
	}
	void RamonaScript::R_jumpslideattack()
	{
		mIsJumpSlideAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_JumpSlideAttack", true);
	}
	void RamonaScript::L_runjumpattack()
	{
		mIsRunJumpAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_RunJumpAttack", true);
	}
	void RamonaScript::R_runjumpattack()
	{
		mIsRunJumpAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_RunJumpAttack", true);
	}
	void RamonaScript::L_runweaponattack()
	{
		mIsRunWeaponAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_RunWeaponAttack", true);
	}
	void RamonaScript::R_runweaponattack()
	{
		mIsRunWeaponAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_RunWeaponAttack", true);
	}
	void RamonaScript::L_runslideattack()
	{
		mIsRunSlideAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_RunSlideAttack", true);
	}
	void RamonaScript::R_runslideattack()
	{
		mIsRunSlideAttack = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_RunSlideAttack", true);
	}
	void RamonaScript::L_fireball()
	{
		mIsFireBall = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_FireBall", true);
	}
	void RamonaScript::R_fireball()
	{
		mIsFireBall = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_FireBall", true);
	}
	void RamonaScript::L_super()
	{
		mIsSuper = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Super", true);
	}
	void RamonaScript::R_super()
	{
		mIsSuper = true;

		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Super", true);
	}
}