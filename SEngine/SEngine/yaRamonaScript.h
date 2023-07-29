#pragma once
#include "yaScript.h"
#include "yaPlayerScript.h"

namespace ya
{
	class RamonaScript : public Script
	{
	public:
		RamonaScript();
		~RamonaScript();


		virtual void Initialize() override;
		virtual void Update() override;

		void JumpStart();
		void JumpComplete();
		//void DJumpComplete();
		void EvadeComplete();
		void NormalAttackComplete();
		void KickComplete();

		void SuperComplete();


		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
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


	private:
		ePlayerState mState = ePlayerState::R_Idle;
		ePlayerState mPreviousState = ePlayerState::R_Idle;

		eDirection mDirection = eDirection::R;

		bool mIsJump = false;
		float mJumpTime = 0.0f;
		float mJumpStartPosY = -100.0f;
		bool mIsDJump = false;

		float mJumpHalfTime = 0.3f;// 점프 체공시간의 절반
		float mJumpHeight = 1.8f;// 점프 높이

		bool mIsRun = false;

		bool mIsEvade = false;

		bool mIsNormalAttack1 = false;
		bool mIsNormalAttack2 = false;
		bool mIsNormalAttack3 = false;
		bool mCanNormalAttack2 = false;
		bool mCanNormalAttack3 = false;
		float mNormalAttack2Time = 0.0f;

		bool mIsKick = false;
		bool mIsRoundKick = false;
		bool mIsBehindKick = false;
	};
}