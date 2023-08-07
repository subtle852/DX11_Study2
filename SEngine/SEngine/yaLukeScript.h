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

			L_Downed,
			R_Downed,

			L_Dead,
			R_Dead,

			L_Flying,
			R_Flying,
			L_Raiding,
			R_Raiding,
		};

		enum class eLukeCombatState
		{
			ArmAttack,
			KickAttack,
			SideKickAttack,
			UpperAttack,

			//Guard,

			End,
		};

	public:
		LukeScript();
		~LukeScript();

		virtual void Initialize() override;
		virtual void Update() override;

		// �̺�Ʈ �Լ�
		void JumpStart();
		void Attacked1Complete();
		void CombatComplete();
		void GuardComplete();
		void Attacked3Complete();
		void DownedComplete();
		void GetUpComplete();

		// �浹 �Լ�
		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		//bool NoneAnimationCondition();
		eDirection GetDirection() { return mDirection; }
		void SetDirection(eDirection dir) { mDirection = dir; }
		eLukeState GetState() { return mState; }
		void ChangeState(eLukeState newState) { mState = newState; }

		// �÷��̾� ���� �Լ�
		bool IsPlayerInDetectionRange()// �÷��̾� �ν� ���� �Լ�: ��� ���·� ���� ����
		{
			// ���� �÷��̾� ������ �Ÿ� ���
			float distanceX = mPlayerPos.x - mPos.x;
			float distanceY = mPlayerPos.y - mPos.y;
			float distanceSquared = distanceX * distanceX + distanceY * distanceY;
			float detectionRangeSquared = mDetectionRange * mDetectionRange;

			// �÷��̾ ���� ���� ���� �ִ��� Ȯ��
			return distanceSquared <= detectionRangeSquared;
		}

		bool IsPlayerInCombatRange()// �÷��̾� ���� ���� �Լ�: ���� ���·� ���� ����
		{
			// ���� �÷��̾� ������ �Ÿ� ���
			float distanceX = mPlayerPos.x - mPos.x;
			float distanceY = mPlayerPos.y - mPos.y;
			float distanceSquared = distanceX * distanceX + distanceY * distanceY;
			float detectionRangeSquared = mCombatRange * mCombatRange;

			// �÷��̾ ���� ���� ���� �ִ��� Ȯ��
			return distanceSquared <= detectionRangeSquared;
		}

		// ���� �Ÿ� ���� �Լ�
		float GetRandomMoveDistance() 
		{
			return baseMoveDistance + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / maxMoveRange));
		}

		// ���� ���� �Լ�
		void Combat();

		void SetAttackedState();

		// State �Լ�
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

		void L_downed();
		void R_downed();

		void L_dead();
		void R_dead();

		void L_flying();
		void R_flying();
		void L_raiding();
		void R_raiding();


	private:
		// �����Ƽ
		float mHp = 100.0f;

		// �ֿ� ����
		eLukeState mState = eLukeState::R_Idle;
		eLukeState mPreviousState = eLukeState::R_Idle;

		eDirection mDirection = eDirection::R;
		int mDirectionInt = 0;// Direction L�� -1 R�� +1

		Vector3 mPos;

		// Player ���� (PlayScene�� static ������ ������Ʈ ��� ����)
		Vector3 mPlayerPos;
		eDirection mPlayerDir;
		ePlayerState mPlayerPreState;
		ePlayerState mPlayerCurState;

		bool mPlayerAttackState[20] = { false, };

		// �÷��̾� �ν� ���� (�ܼ�)
		const float mDetectionRange = 1.5f;
		bool mDetected = false;

		// �÷��̾� ���� ���� (����, ���...)
		const float mCombatRange = 0.7f;
		bool mCombated = false;

		// AI �⺻ �̵� �Ÿ��� �̵� ���� ���� ��
		float baseMoveDistance = 0.1f;
		float maxMoveRange = 0.3f;

		// AI �̵� ���� ������ ���� Ÿ�̸� ����
		float mMoveTimer;
		const float mMoveInterval = 2.0f; // 2�ʸ��� �������� ���� ����

		// AI ���� ������ ���� Ÿ�̸� ����
		float mCombatTimer = 0.0f;
		float mCombatInterval = 3.0f;
		
		// AI Ž�� �Ÿ����� �÷��̾� �߰� ��, ��� or �޸��� ���� ����
		int mRandWaitOrRun = -100;
		float mRunSpeed = 0.4f;

		// NormalAttack �޺� �� �浹ü�� �׽� �����Ǿ� ������ ������ �浹 �ʱ�ȭ�� ���� ����
		bool mIsNormalAttackComboInit = false;

		// �浹 ���°� ó������ Ȯ���ϱ� ���� ����
		int mIsCollidingFirst = 0;

		// ���� �Լ� �̿��� ���� ����
		std::random_device rd;

		// �ݶ��̴�
		Collider2D* mBodyCd = nullptr;
		Collider2D* mSkillCd = nullptr;

		// State ����
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

		bool mIsDowned = false;
		//bool mIsDead = false;

		bool mIsFlying = false;
		bool mIsRaiding = false;
	};
}