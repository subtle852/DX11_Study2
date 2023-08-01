#pragma once
#include "yaScript.h"
#include "yaPlayerScript.h"

namespace ya
{
	class RamonaScript : public Script
	{
		struct RamonaAbility
		{
			float mHp = 100.0f;
			int mHeart = 3;
			float mGP = 0;
			float mCoin = 0.0f;
		};

	public:
		RamonaScript();
		~RamonaScript();

		virtual void Initialize() override;
		virtual void Update() override;

		eDirection GetDirection() {	return mDirection; }

		// 이벤트 함수
		void JumpStart();
		void JumpComplete();

		void EvadeComplete();

		void NormalAttackComplete();
		void KickComplete();

		void WeaponAttackComplete();
		void JumpAttackComplete();
		void RunAttackComplete();

		void FireBallComplete();
		void SuperComplete();

		// 충돌 함수
		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		// 기존 애니메이션이 동작되면 안되는 조건 
		// ex. 점프 도중 키입력이 있다고 해서 다른 애니메이션이 진행되면 안됨
		bool NoneAnimationCondition(); 

		// State 함수
		void L_idle();
		void R_idle();

		void L_walk();
		void R_walk();

		void L_run();
		void R_run();

		void L_jump();
		void R_jump();

		void L_djump();
		void R_djump();

		void L_guard();
		void R_guard();

		void L_evade();
		void R_evade();

		void L_normalattack1();
		void R_normalattack1();
		void L_normalattack2();
		void R_normalattack2();
		void L_normalattack3();
		void R_normalattack3();

		void L_kick();
		void R_kick();
		void L_roundkick();
		void R_roundkick();
		void L_behindkick();
		void R_behindkick();

		void L_weaponnormalattack();
		void R_weaponnormalattack();
		void L_weapondownattack();
		void R_weapondownattack();
		void L_weaponsideattack();
		void R_weaponsideattack();
		void L_weaponstabattack();
		void R_weaponstabattack();

		void L_jumpdownattack();
		void R_jumpdownattack();
		void L_jumpslideattack();
		void R_jumpslideattack();
		void L_runjumpattack();
		void R_runjumpattack();

		void L_runweaponattack();
		void R_runweaponattack();
		void L_runslideattack();
		void R_runslideattack();

		void L_fireball();
		void R_fireball();
		void L_super();
		void R_super();

	private:
		// 어빌리티
		RamonaAbility mAbilty;

		// 주요 상태
		ePlayerState mState = ePlayerState::R_Idle;
		ePlayerState mPreviousState = ePlayerState::R_Idle;

		eDirection mDirection = eDirection::R;

		// State 변수
		// 점프 관련 변수
		bool mIsJump = false;
		float mJumpTime = 0.0f;// 점프 체공 시간 측정
		float mJumpStartPosY = -100.0f;// 점프 시작 위치 (불가능한 -100.0f로 초기화)
		bool mIsDJump = false;
		float mJumpHalfTime = 0.3f;// 점프 체공시간의 절반
		float mJumpHeight = 1.8f;// 점프 높이

		bool mIsRun = false;

		bool mIsEvade = false;

		// 콤보 공격 변수
		bool mIsNormalAttack1 = false;
		bool mIsNormalAttack2 = false;
		bool mIsNormalAttack3 = false;
		bool mCanNormalAttack2 = false;
		bool mCanNormalAttack3 = false;
		float mNormalAttack2Time = 0.0f;// NormalAttack2 실행 시간 측정

		bool mIsKick = false;
		bool mIsRoundKick = false;
		bool mIsBehindKick = false;

		bool mIsWeaponNormal = false;
		bool mIsWeaponDown = false;
		bool mIsWeaponSide = false;
		bool mIsWeaponStab = false;

		bool mIsJumpDown = false;
		bool mIsJumpSlide = false;
		bool mIsRunJump = false;

		bool mIsRunWeapon = false;
		bool mIsRunSlide = false;

		bool mIsFireBall = false;
		bool mIsSuper = false;

		// 충돌체
		Collider2D* mBodyCd = nullptr;
		Collider2D* mUpperCd = nullptr;
		Collider2D* mLowerCd = nullptr;
		Collider2D* mBothCd = nullptr;
		Collider2D* mAllCd = nullptr;
	};
}