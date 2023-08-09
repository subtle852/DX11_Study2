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

		// private �������� �Լ�
		eDirection GetDirection() { return mDirection; }
		ePlayerState GetState() { return mState; }

		// �̺�Ʈ �Լ�
		void EvadeComplete();

		void NormalAttackComplete();
		void KickComplete();

		void WeaponAttackComplete();
		void JumpAttackComplete();
		void RunAttackComplete();

		void FireBallComplete();
		void SuperComplete();

		void StunComplete();
		void KnockDownComplete();
		void DownedComplete();
		void GetUpComplete();

		// �浹 �Լ�
		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:

		//// ���� �Լ�

		// �ٸ� �ִϸ��̼� �������ε� �¿���� Ű�� �����ٰ� �ؼ� 
		// Ư�� �ִϸ��̼�(ex. Walk)�� ����Ǹ� �ȵǱ⿡ �ٸ� �ִϸ��̼��� ���������� Ȯ���ϴ� ����
		bool NoneAnimationCondition();

		// �¿���� �̵��� ���ƾ��ϴ� ��� ex. FireBall
		bool CanMoveCondition();

		// ������ ���ƾ��ϴ� ���
		bool CanJumpCondition();

		// ���� ��ų ���߿��� �ٸ� ���� ��ų�� ������� �ʱ����� ����
		// �޺� ��ų�̳� ���� ��ų(ex. D + down)�� �� ������ ����ؼ��� �ȵ�
		// ���� ��ų�� true�� ���¿��� ���� ��ų�� ���� �Ǳ� ����
		bool CanAttackCondition();

		// State�� �ٲ�� �ȵǴ� ���� ex. Stun, KnockDown,... �̷� ���� �����߿� �ٸ� ���·� ��ȯ�Ǹ� �ȵ�
		bool CanChangeState();

		//// State �Լ�
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

		void L_stun();
		void R_stun();
		void L_backstun();
		void R_backstun();
		void L_knockdown();
		void R_knockdown();

		void L_downed();
		void R_downed();

		void L_getup();
		void R_getup();

	private:
		// �����Ƽ
		RamonaAbility mAbilty;

		// �ֿ� ����
		ePlayerState mState = ePlayerState::R_Idle;
		ePlayerState mPreviousState = ePlayerState::R_Idle;

		eDirection mDirection = eDirection::R;

		//// State ����
		
		// Walk
		float mWalkSpeed = 0.7f;

		// Run
		bool mIsRun = false;
		float mRunSpeed1 = 0.4f;// �¿� �̵�
		float mRunSpeed2 = 0.3f;// ���� �̵�

		// Jump
		bool mIsJump = false;
		float mJumpTime = 0.0f;// ���� ü�� �ð� ����
		float mJumpStartPosY = -100.0f;// ���� ���� ��ġ (�Ұ����� -100.0f�� �ʱ�ȭ)
		bool mIsDJump = false;
		float mJumpHalfTime = 0.3f;// ���� ü���ð��� ����
		float mJumpHeight = 1.8f;// ���� ����
		float mDJumpHeight = 2.3f;// �������� ����

		// Guard, Evade
		bool mIsGuard = false;
		bool mIsEvade = false;

		// �޺� ����
		bool mIsNormalAttack1 = false;
		bool mIsNormalAttack2 = false;
		bool mIsNormalAttack3 = false;
		bool mCanNormalAttack2 = false;
		bool mCanNormalAttack3 = false;
		float mNormalAttack2Time = 0.0f;// NormalAttack2 ���� �ð� ����

		// �޺� ���� ������ ������ ����
		bool mIsKickAttack = false;
		bool mIsRoundKickAttack = false;
		bool mIsBehindKickAttack = false;

		bool mIsWeaponNormalAttack = false;
		bool mIsWeaponDownAttack = false;
		bool mIsWeaponSideAttack = false;
		bool mIsWeaponStabAttack = false;

		bool mIsJumpDownAttack = false;
		bool mIsJumpSlideAttack = false;
		bool mIsRunJumpAttack = false;

		bool mIsRunWeaponAttack = false;
		bool mIsRunSlideAttack = false;

		bool mIsFireBall = false;
		bool mIsSuper = false;

		// Under Attack
		bool mIsStun = false;
		bool mIsKnockDown = false;
		bool mIsDowned = false;
		bool mIsGetUp = false;
		bool mIsBackStun = false;

		// �浹ü
		Collider2D* mBodyCd = nullptr;
		Collider2D* mUpperCd = nullptr;
		Collider2D* mLowerCd = nullptr;
		Collider2D* mBothCd = nullptr;
		Collider2D* mBackCd = nullptr;
		Collider2D* mAllCd = nullptr;

		// � ���� ��ų�� ��������� ��� �ִ� bool �迭
		bool mAttackState[20] = { false, };

		// mAttackState �迭 ���� �ּҸ� �����ִ� �Լ�
	public:
		const bool* GetAttackState() { return &mAttackState[0]; }

	private:
		// �� ���� ��ų ���¸� ��� �ִ� bool �迭
		bool mEnemyAttackState[10] = { false, };

		// �浹�� ó������ Ȯ���ϴ� ����
		int mIsCollidingFirst = 0;
	};
}