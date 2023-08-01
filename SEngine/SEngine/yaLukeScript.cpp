#include "yaLukeScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaPlayScene.h"

namespace ya
{
	LukeScript::LukeScript()
	{
	}
	LukeScript::~LukeScript()
	{
	}
	void LukeScript::Initialize()
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �ִϸ��̼�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		std::shared_ptr<Texture> atlas
			= Resources::Load<Texture>(L"Luke_Idle", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_IDLE.png");
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"R_Idle", atlas, enums::eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);//, Vector2::Zero, 0.05f);
		at->Create(L"L_Idle", atlas, enums::eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);

		atlas
			= Resources::Load<Texture>(L"Luke_Angry", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_ANGRY.png");
		at->Create(L"R_Angry", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);
		at->Create(L"L_Angry", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);

		atlas
			= Resources::Load<Texture>(L"Luke_Walk", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_WALK.png");
		at->Create(L"R_Walk", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(1385.0f / 12.0f, 116.0f), 12);
		at->Create(L"L_Walk", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(1385.0f / 12.0f, 116.0f), 12);

		atlas
			= Resources::Load<Texture>(L"Luke_Run", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_RUN.png");
		at->Create(L"R_Run", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);
		at->Create(L"L_Run", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);

		atlas
			= Resources::Load<Texture>(L"ArmAttack", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_ARM.png");
		at->Create(L"R_ArmAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);
		at->Create(L"L_ArmAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);

		atlas
			= Resources::Load<Texture>(L"Luke_KickAttack", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_KICK.png");
		at->Create(L"R_KickAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(808.0f / 7.0f, 116.0f), 7);
		at->Create(L"L_KickAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(808.0f / 7.0f, 116.0f), 7);

		atlas
			= Resources::Load<Texture>(L"Luke_SideKickAttack", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_SIDEKICK.png");
		at->Create(L"R_SideKickAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(808.0f / 7.0f, 116.0f), 7);
		at->Create(L"L_SideKickAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(808.0f / 7.0f, 116.0f), 7);

		atlas
			= Resources::Load<Texture>(L"Luke_UpperAttack", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_UPPER.png");
		at->Create(L"R_UpperAttack", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);
		at->Create(L"L_UpperAttack", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);

		atlas
			= Resources::Load<Texture>(L"Luke_Guard", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_GUARD.png");
		at->Create(L"R_Guard", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(693.0f / 6.0f, 116.0f), 6);
		at->Create(L"L_Guard", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(693.0f / 6.0f, 116.0f), 6);

		atlas
			= Resources::Load<Texture>(L"Luke_Attacked1", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_ATTACKED1.png");
		at->Create(L"R_Attacked1", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(347.0f / 3.0f, 116.0f), 3);
		at->Create(L"L_Attacked1", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(347.0f / 3.0f, 116.0f), 3);

		atlas
			= Resources::Load<Texture>(L"Luke_Attacked2", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_ATTACKED2.png");
		at->Create(L"R_Attacked2", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);
		at->Create(L"L_Attacked2", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);

		atlas
			= Resources::Load<Texture>(L"Luke_Attacked3", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_ATTACKED3.png");
		at->Create(L"R_Attacked3", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(1616.0f / 14.0f, 116.0f), 14);
		at->Create(L"L_Attacked3", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(1616.0f / 14.0f, 116.0f), 14);

		atlas
			= Resources::Load<Texture>(L"Luke_Attacked4", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_ATTACKED4.png");
		at->Create(L"R_Attacked4", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);
		at->Create(L"L_Attacked4", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);

		atlas
			= Resources::Load<Texture>(L"Luke_GetUp", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_GETUP.png");
		at->Create(L"R_GetUp", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);
		at->Create(L"L_GetUp", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(923.0f / 8.0f, 116.0f), 8);

		atlas
			= Resources::Load<Texture>(L"Luke_Dead", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_DEAD.png");
		at->Create(L"R_Dead", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);
		at->Create(L"L_Dead", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);

		atlas
			= Resources::Load<Texture>(L"Luke_Flying", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_FLYING.png");
		at->Create(L"R_Flying", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);
		at->Create(L"L_Flying", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);

		atlas
			= Resources::Load<Texture>(L"Luke_Raiding", L"..\\Resources\\TEXTURE\\STAGE01\\ENEMY\\LUKE\\LUKE_RAIDING.png");
		at->Create(L"R_Raiding", atlas, eAnimationType::Front, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);
		at->Create(L"L_Raiding", atlas, eAnimationType::Back, Vector2(0.0f, 0.0f), Vector2(462.0f / 4.0f, 116.0f), 4);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �̺�Ʈ 
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		at = GetOwner()->GetComponent<Animator>();

		at->CompleteEvent(L"L_Attacked1") = std::bind(&LukeScript::Attacked1Complete, this);
		at->CompleteEvent(L"R_Attacked1") = std::bind(&LukeScript::Attacked1Complete, this);

		at->CompleteEvent(L"L_ArmAttack") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"R_Attacked1") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"L_KickAttack") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"R_KickAttack") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"L_SideKickAttack") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"R_SideKickAttack") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"L_UpperAttack") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"R_UpperAttack") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"L_Guard") = std::bind(&LukeScript::CombatComplete, this);
		at->CompleteEvent(L"R_Guard") = std::bind(&LukeScript::CombatComplete, this);


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �ʱ�ȭ 
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		mMoveTimer = 0.0f;

		if (rand() % 2 == 0)
		{
			mDirection = eDirection::L;
			mDirectionInt = -1;
		}
		else
		{
			mDirection = eDirection::R;
			mDirectionInt = +1;
		}
	}
	void LukeScript::Update()
	{
		if (mPreviousState != mState)
		{
			switch (mState)
			{
			case eLukeState::L_Idle:
				L_idle();
				break;
			case eLukeState::R_Idle:
				R_idle();
				break;

			case eLukeState::L_Angry:
				L_angry();
				break;
			case eLukeState::R_Angry:
				R_angry();
				break;

			case eLukeState::L_Walk:
				L_walk();
				break;
			case eLukeState::R_Walk:
				R_walk();
				break;

			case eLukeState::L_Run:
				L_run();
				break;
			case eLukeState::R_Run:
				R_run();
				break;

			case eLukeState::L_ArmAttack:
				L_armattack();
				break;
			case eLukeState::R_ArmAttack:
				R_armattack();
				break;
			case eLukeState::L_KickAttack:
				L_kickattack();
				break;
			case eLukeState::R_KickAttack:
				R_kickattack();
				break;
			case eLukeState::L_SideKickAttack:
				L_sidekickattack();
				break;
			case eLukeState::R_SideKickAttack:
				R_sidekickattack();
				break;
			case eLukeState::L_UpperAttack:
				L_upperattack();
				break;
			case eLukeState::R_UpperAttack:
				R_upperattack();
				break;

			case eLukeState::L_Guard:
				L_guard();
				break;
			case eLukeState::R_Guard:
				R_guard();
				break;

			case eLukeState::L_Attacked1:
				L_attacked1();
				break;
			case eLukeState::R_Attacked1:
				R_attacked1();
				break;
			case eLukeState::L_Attacked2:
				L_attacked2();
				break;
			case eLukeState::R_Attacked2:
				R_attacked2();
				break;
			case eLukeState::L_Attacked3:
				L_attacked3();
				break;
			case eLukeState::R_Attacked3:
				R_attacked3();
				break;
			case eLukeState::L_Attacked4:
				L_attacked4();
				break;
			case eLukeState::R_Attacked4:
				R_attacked4();
				break;

			case eLukeState::L_GetUp:
				L_getup();
				break;
			case eLukeState::R_GetUp:
				R_getup();
				break;

			case eLukeState::L_Dead:
				L_dead();
				break;
			case eLukeState::R_Dead:
				R_dead();
				break;

			case eLukeState::L_Flying:
				L_flying();
				break;
			case eLukeState::R_Flying:
				R_flying();
				break;
			case eLukeState::L_Raiding:
				L_raiding();
				break;
			case eLukeState::R_Raiding:
				R_raiding();
				break;

			default:
					break;
			}
		}

		mPreviousState = mState;

		// ���� ��ġ ������Ʈ
		Transform* tr = this->GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		mPos = pos;

		// �÷��̾� ��ġ, ���� ������Ʈ
		if (PlayScene::IsPlayerExist())
		{
			mPlayerPos = PlayScene::GetPlayerPosition();
			mPlayerDir = PlayScene::GetPlayerDirection();
		}


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// AI
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// ������ ���ϰ� ���� ���� �Ʒ��� ���� ��ȭ�� ������ �ȵ�
		// ���� ������ ���ϴ� ������ ���ļ� �Լ��� ��ü ����
		if (mIsAttacked1 == false)
		{
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// Ž���Ÿ� �� �÷��̾� O
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (IsPlayerInDetectionRange())// Ž���Ÿ� �� �÷��̾� O
			{
				if (mDetected == false)// ó�� �������� ����
				{
					// �÷��̾� �� �������� ���� ����� ��
					if (mPlayerPos.x < mPos.x)
					{
						mDetected = true;
						mDirection = eDirection::L;
						ChangeState(eLukeState::L_Idle);
					}
					else
					{
						mDetected = true;

						mDirection = eDirection::R;
						ChangeState(eLukeState::R_Idle);
					}
				}

				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �����Ÿ� �� �÷��̾� O
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (IsPlayerInCombatRange())
				{
					mCombated = true;

					mCombatTimer -= Time::DeltaTime();

					if (mCombatTimer <= 0.0f)
					{
						// ���� ��� ��ų�� �� �ϳ��� �������� ����
						//std::mt19937 mt(1234);// ������ �õ带 ������ �ٸ� �ӽſ����� ������ �������ڰ� ����
						//std::uniform_int_distribution<int> dist(0, 4);
						//int randStateNum = dist(mt);
						int randStateNum = rand() % (int)eLukeCombatState::End;

						switch (static_cast<eLukeCombatState>(randStateNum))
						{
						case eLukeCombatState::ArmAttack:
							if (mPlayerPos.x < mPos.x)
								ChangeState(eLukeState::L_ArmAttack);
							else
								ChangeState(eLukeState::R_ArmAttack);
							break;

						case eLukeCombatState::KickAttack:
							if (mPlayerPos.x < mPos.x)
								ChangeState(eLukeState::L_KickAttack);
							else
								ChangeState(eLukeState::L_KickAttack);
							break;

						case eLukeCombatState::SideKickAttack:
							if (mPlayerPos.x < mPos.x)
								ChangeState(eLukeState::L_SideKickAttack);
							else
								ChangeState(eLukeState::R_SideKickAttack);
							break;

						case eLukeCombatState::UpperAttack:
							if (mPlayerPos.x < mPos.x)
								ChangeState(eLukeState::L_UpperAttack);
							else
								ChangeState(eLukeState::R_UpperAttack);
							break;

						case eLukeCombatState::Guard:
							if (mPlayerPos.x < mPos.x)
								ChangeState(eLukeState::L_Guard);
							else
								ChangeState(eLukeState::R_Guard);
							break;
							break;

						default:
							break;
						}

						mCombatTimer = mCombatInterval;
					}
				}

				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �����Ÿ� �� �÷��̾� X
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				else
				{
					mDetected = false;// �÷��̾� �� �������� ���� ���ֱ� ���� ó�� Detect �Ǵ� ���·� ��ȯ
					mCombated = false;

					mCombatTimer = 0.0f;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// Ž���Ÿ� �� �÷��̾� X
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (!IsPlayerInDetectionRange())
			{
				mDetected = false;

				// �̵� Ÿ�̸� ����
				mMoveTimer -= Time::DeltaTime();

				if (mMoveTimer <= 0.0f) 
				{
					// �����ϰ� �̵� ���� ����
					if (rand() % 2 == 0)
					{
						mDirection = eDirection::L;
						mDirectionInt = -1;
					}
					else
					{
						mDirection = eDirection::R;
						mDirectionInt = +1;
					} // -1 �Ǵ� 1�� �����ϰ� ����

					// Ÿ�̸� �ʱ�ȭ
					mMoveTimer = mMoveInterval;
				}

				// ���� �̵� ����
				float moveDistance = GetRandomMoveDistance();
				Transform* tr = this->GetOwner()->GetComponent<Transform>();
				Vector3 pos = tr->GetPosition();
				pos.x += mDirectionInt * moveDistance * Time::DeltaTime();
				tr->SetPosition(pos);

				if (mDirectionInt == -1)
				{
					mDirection = eDirection::L;
					ChangeState(eLukeState::L_Walk);
				}
				else
				{
					mDirection = eDirection::R;
					ChangeState(eLukeState::R_Walk);
				}
				
				// ȭ�� ���� ���� ���� ���� ����� �ʵ��� ó��
				if (mPos.x < -2.8f)////////////////////////////////////////////////////////////////////////// ���� ���� CameraPos��
				{
					//mPos.x = 0;
					mDirectionInt = 1; // �������� ���� ��ȯ
					mDirection = eDirection::R;
					ChangeState(eLukeState::R_Walk);
				}
				else if (mPos.x > 2.8f) 
				{
					//mPos.x = screenWidth;
					mDirectionInt = -1; // �������� ���� ��ȯ
					mDirection = eDirection::L;
					ChangeState(eLukeState::L_Walk);
				}
			}
		}

	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �̺�Ʈ
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void LukeScript::JumpStart()
	{
	}

	void LukeScript::Attacked1Complete()
	{
		mIsAttacked1 = true;// ���� ������
		ChangeState(eLukeState::L_Angry);
	}

	void LukeScript::CombatComplete()
	{
		// �Ʒ��� ���� ��ȯ ������ �ش� �ִϸ��̼��̳� �ش� ���·� ��ȯ ��, ���ְ� 
		// ���⼭, ����� ��
		//if (mIsArm == true) mIsKick mIsSideKick mIsUpper mIsGuard
		//	mIsArm = false;

		if (mPlayerPos.x < mPos.x)
			ChangeState(eLukeState::L_Idle);
		else
			ChangeState(eLukeState::R_Idle);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// �浹
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void LukeScript::OnCollisionEnter(Collider2D* other)
	{
	
	}

	void LukeScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetState() == eColliderState::Active)
		{
			if (other->GetOwner()->GetName() == L"Ramona")
			{
				if (mPlayerDir == eDirection::L)
				{
					if (mPos.x < mPlayerPos.x)// ĳ���Ͱ� ���� �����̴� ��(����)�� ������ �ִٸ� ���� ������ ����
					{
						if (mIsAttacked1 == false)
						{
							ChangeState(eLukeState::L_Attacked1);
							mIsAttacked1 = true;
						}
					}
				}
				else
				{
					if (mPos.x > mPlayerPos.x)// ĳ���Ͱ� ���� �����̴� ��(����)�� ������ �ִٸ� ���� ������ ����
					{
						if (mIsAttacked1 == false)
						{
							ChangeState(eLukeState::L_Attacked1);
							mIsAttacked1 = true;
						}
					}

				}
			}
		}
		if (other->GetState() == eColliderState::NoneActive)
		{
			if (other->GetOwner()->GetName() == L"Ramona")
			{
				// OnCollsionExit ���·� �浹�� ������ ���� �ƴ� 
				// �÷��̾��� ������ ������ �÷��̾��� �ݶ��̴��� NoneActive�� ����Ǵ� ���
				mIsAttacked1 = false;
			}
		}
	}

	void LukeScript::OnCollisionExit(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Ramona")
		{
			// OnCollsionExit ���·� �浹�� ������ false�� ����
			mIsAttacked1 = false;
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// ���� �ִϸ��̼� �Լ�
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void LukeScript::L_idle()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Idle", true);
	}
	void LukeScript::R_idle()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Idle", true);
	}
	void LukeScript::L_angry()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Angry", true);
	}
	void LukeScript::R_angry()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Angry", true);
	}
	void LukeScript::L_walk()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Walk", true);
	}
	void LukeScript::R_walk()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Walk", true);
	}
	void LukeScript::L_run()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Run", true);
	}
	void LukeScript::R_run()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Run", true);
	}
	void LukeScript::L_armattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_ArmAttack", true);
	}
	void LukeScript::R_armattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_ArmAttack", true);
	}
	void LukeScript::L_kickattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_KickAttack", true);
	}
	void LukeScript::R_kickattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_KickAttack", true);
	}
	void LukeScript::L_sidekickattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_SideKickAttack", true);
	}
	void LukeScript::R_sidekickattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_SideKickAttack", true);
	}
	void LukeScript::L_upperattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_UpperAttack", true);
	}
	void LukeScript::R_upperattack()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_UpperAttack", true);
	}
	void LukeScript::L_guard()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Guard", true);
	}
	void LukeScript::R_guard()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Guard", true);
	}
	void LukeScript::L_attacked1()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Attacked1", true);
	}
	void LukeScript::R_attacked1()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Attacked1", true);
	}
	void LukeScript::L_attacked2()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Attacked2", true);
	}
	void LukeScript::R_attacked2()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Attacked2", true);
	}
	void LukeScript::L_attacked3()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Attacked3", true);
	}
	void LukeScript::R_attacked3()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Attacked3", true);
	}
	void LukeScript::L_attacked4()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Attacked4", true);
	}
	void LukeScript::R_attacked4()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Attacked4", true);
	}
	void LukeScript::L_getup()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_GetUp", true);
	}
	void LukeScript::R_getup()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_GetUp", true);
	}
	void LukeScript::L_dead()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Dead", true);
	}
	void LukeScript::R_dead()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Dead", true);
	}
	void LukeScript::L_flying()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Flying", true);
	}
	void LukeScript::R_flying()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Flying", true);
	}
	void LukeScript::L_raiding()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"L_Raiding", true);
	}
	void LukeScript::R_raiding()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"R_Raiding", true);
	}
}