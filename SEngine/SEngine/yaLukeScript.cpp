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
															// 애니메이션
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
															// 이벤트 
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
															// 초기화 
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

		// 본인 위치 업데이트
		Transform* tr = this->GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		mPos = pos;

		// 플레이어 위치, 방향 업데이트
		if (PlayScene::IsPlayerExist())
		{
			mPlayerPos = PlayScene::GetPlayerPosition();
			mPlayerDir = PlayScene::GetPlayerDirection();
		}


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// AI
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// 공격을 당하고 있을 때는 아래의 상태 변화가 있으면 안됨
		// 추후 공격을 당하는 변수들 합쳐서 함수로 대체 예정
		if (mIsAttacked1 == false)
		{
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// 탐지거리 내 플레이어 O
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (IsPlayerInDetectionRange())// 탐지거리 내 플레이어 O
			{
				if (mDetected == false)// 처음 감지했을 때만
				{
					// 플레이어 쪽 방향으로 설정 해줘야 함
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
															// 전투거리 내 플레이어 O
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (IsPlayerInCombatRange())
				{
					mCombated = true;

					mCombatTimer -= Time::DeltaTime();

					if (mCombatTimer <= 0.0f)
					{
						// 공격 방어 스킬들 중 하나를 랜덤으로 실행
						//std::mt19937 mt(1234);// 동일한 시드를 넣으면 다른 머신에서도 동일한 랜덤숫자가 뽑힘
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
															// 전투거리 내 플레이어 X
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				else
				{
					mDetected = false;// 플레이어 쪽 방향으로 설정 해주기 위해 처음 Detect 되는 상태로 전환
					mCombated = false;

					mCombatTimer = 0.0f;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// 탐지거리 내 플레이어 X
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (!IsPlayerInDetectionRange())
			{
				mDetected = false;

				// 이동 타이머 감소
				mMoveTimer -= Time::DeltaTime();

				if (mMoveTimer <= 0.0f) 
				{
					// 랜덤하게 이동 방향 변경
					if (rand() % 2 == 0)
					{
						mDirection = eDirection::L;
						mDirectionInt = -1;
					}
					else
					{
						mDirection = eDirection::R;
						mDirectionInt = +1;
					} // -1 또는 1로 랜덤하게 설정

					// 타이머 초기화
					mMoveTimer = mMoveInterval;
				}

				// 랜덤 이동 로직
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
				
				// 화면 좌측 끝과 우측 끝을 벗어나지 않도록 처리
				if (mPos.x < -2.8f)////////////////////////////////////////////////////////////////////////// 수정 예정 CameraPos로
				{
					//mPos.x = 0;
					mDirectionInt = 1; // 우측으로 방향 전환
					mDirection = eDirection::R;
					ChangeState(eLukeState::R_Walk);
				}
				else if (mPos.x > 2.8f) 
				{
					//mPos.x = screenWidth;
					mDirectionInt = -1; // 좌측으로 방향 전환
					mDirection = eDirection::L;
					ChangeState(eLukeState::L_Walk);
				}
			}
		}

	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// 이벤트
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void LukeScript::JumpStart()
	{
	}

	void LukeScript::Attacked1Complete()
	{
		mIsAttacked1 = true;// 오류 방지용
		ChangeState(eLukeState::L_Angry);
	}

	void LukeScript::CombatComplete()
	{
		// 아래의 상태 변환 변수를 해당 애니메이션이나 해당 상태로 변환 시, 켜주고 
		// 여기서, 꺼줘야 함
		//if (mIsArm == true) mIsKick mIsSideKick mIsUpper mIsGuard
		//	mIsArm = false;

		if (mPlayerPos.x < mPos.x)
			ChangeState(eLukeState::L_Idle);
		else
			ChangeState(eLukeState::R_Idle);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// 충돌
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
					if (mPos.x < mPlayerPos.x)// 캐릭터가 좌측 방향이니 적(본인)이 우측에 있다면 공격 당하지 않음
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
					if (mPos.x > mPlayerPos.x)// 캐릭터가 우측 방향이니 적(본인)이 좌측에 있다면 공격 당하지 않음
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
				// OnCollsionExit 상태로 충돌이 끝나는 것이 아닌 
				// 플레이어의 공격이 끝나고 플레이어의 콜라이더가 NoneActive로 변경되는 경우
				mIsAttacked1 = false;
			}
		}
	}

	void LukeScript::OnCollisionExit(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Ramona")
		{
			// OnCollsionExit 상태로 충돌이 끝나면 false로 변경
			mIsAttacked1 = false;
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
															// 상태 애니메이션 함수
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