#pragma once
#include "yaScript.h"

namespace ya
{
	class LukeScript : public Script
	{
		enum class eLukeState
		{
			L_Idle,
			R_Idle,
			L_Angry,
			R_Angry,

			L_Walk,
			R_Walk,
			L_Run,
			R_Run,

			L_ArmAttack,
			R_ArmAttack,
			L_KickAttack,
			R_KickAttack,
			L_SideKickAttack,
			R_SideKickAttack,
			L_UpperAttack,
			R_UpperAttack,

			L_Guard,
			R_Guard,

			L_Attacked1,
			R_Attacked1,
			L_Attacked2,
			R_Attacked2,
			L_Attacked3,
			R_Attacked3,
			L_Attacked4,
			R_Attacked4,

			L_GetUp,
			R_GetUp,

			L_Dead,
			R_Dead,

			L_Flying,
			R_Flying,
			L_Raiding,
			R_Raiding,
		};

	public:
		LukeScript();
		~LukeScript();

		virtual void Initialize() override;
		virtual void Update() override;

		void JumpStart();
		void Attacked1Complete();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		//bool NoneAnimationCondition();

		void ChangeState(eLukeState newState) 
		{
			mState = newState;
		}

		void SetPlayerPosition(float playerX, float playerY) 
		{
			mPlayerPos.x = playerX;
			mPlayerPos.y = playerY;
		}

		bool IsPlayerInDetectionRange()
			// 탐지되면 계속 추적상태로 전환되어서 따라 다니고 거리 더 가까워지면 IsPlayerInAttacRange를 체크하고 공격하도록 만들어야 함
		{
			// 적과 플레이어 사이의 거리 계산
			float distanceX = mPlayerPos.x - mPos.x;
			float distanceY = mPlayerPos.y - mPos.y;
			float distanceSquared = distanceX * distanceX + distanceY * distanceY;
			float detectionRangeSquared = mDetectionRange * mDetectionRange;

			// 플레이어가 감지 범위 내에 있는지 확인
			return distanceSquared <= detectionRangeSquared;
		}

		void L_idle();
		void R_idle();

		void L_angry();
		void R_angry();

		void L_walk();
		void R_walk();

		void L_run();
		void R_run();

		void L_armattack();
		void R_armattack();
		void L_kickattack();
		void R_kickattack();
		void L_sidekickattack();
		void R_sidekickattack();
		void L_upperattack();
		void R_upperattack();

		void L_guard();
		void R_guard();

		void L_attacked1();
		void R_attacked1();
		void L_attacked2();
		void R_attacked2();
		void L_attacked3();
		void R_attacked3();
		void L_attacked4();
		void R_attacked4();

		void L_getup();
		void R_getup();

		void L_dead();
		void R_dead();

		void L_flying();
		void R_flying();
		void L_raiding();
		void R_raiding();


	private:
		float mHp = 100.0f;

		eLukeState mState = eLukeState::R_Idle;
		eLukeState mPreviousState = eLukeState::R_Idle;

		eDirection mDirection = eDirection::R;

		Vector3 mPos;

		Vector3 mPlayerPos;

		float mDetectionRange = 1.5f;

		bool mDectected = false;// 플레이어 감지

		bool mIsIdle = false;
		bool mIsAngry = false;
		bool mIsWalk = false;
		bool mIsRun = false;
		
		bool mIsArm = false;
		bool mIsKick = false;
		bool mIsSideKick = false;
		bool mIsUpper = false;

		bool mIsGuard = false;

		bool mIsAttacked1 = false;
		bool mIsAttacked2 = false;
		bool mIsAttacked3 = false;
		bool mIsAttacked4 = false;

		bool mIsGetUp = false;

		bool mIsDead = false;

		bool mIsFlying = false;
		bool mIsRaiding = false;
	};
}