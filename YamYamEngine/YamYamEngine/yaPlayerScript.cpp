#include "yaPlayerScript.h"
#include "yaCameraScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaAnimator.h"
#include "yaResources.h"

namespace ya
{
	PlayerScript::PlayerScript()
	{

	}

	PlayerScript::~PlayerScript()
	{

	}

	void PlayerScript::Initialize()
	{
		std::shared_ptr<Texture> atlas
			= Resources::Load<Texture>(L"Walk", L"..\\Resources\\Texture\\Walk.png");
		Animator*at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Walk", atlas, Vector2(0.0f, 0.0f), Vector2(210.0f / 6.0f, 68.0f), 6);

		atlas
			= Resources::Load<Texture>(L"Run", L"..\\Resources\\Texture\\Run.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Run", atlas, Vector2(0.0f, 0.0f), Vector2(424.0f / 8.0f, 67.0f), 8);

		atlas
			= Resources::Load<Texture>(L"Jump", L"..\\Resources\\Texture\\Jump.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Jump", atlas, Vector2(0.0f, 0.0f), Vector2(432.0f / 9.0f, 78.0f), 9);

		//

		atlas
			= Resources::Load<Texture>(L"NormalAttack", L"..\\Resources\\Texture\\NormalAttack.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"NormalAttack", atlas, Vector2(0.0f, 0.0f), Vector2(186.0f / 3.0f, 70.0f), 3);

		atlas
			= Resources::Load<Texture>(L"Kick", L"..\\Resources\\Texture\\Kick.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Kick", atlas, Vector2(0.0f, 0.0f), Vector2(310.0f / 5.0f, 70.0f), 5);

		atlas
			= Resources::Load<Texture>(L"RoundKick", L"..\\Resources\\Texture\\RoundKick.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"RoundKick", atlas, Vector2(0.0f, 0.0f), Vector2(897.0f / 13.0f, 72.0f), 13);

		atlas
			= Resources::Load<Texture>(L"Guard", L"..\\Resources\\Texture\\Guard.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Guard", atlas, Vector2(0.0f, 0.0f), Vector2(219.0f / 5.0f, 70.0f), 5);

		atlas
			= Resources::Load<Texture>(L"Evade", L"..\\Resources\\Texture\\Evade.png");
		at = this->GetOwner()->GetComponent<Animator>();
		at->Create(L"Evade", atlas, Vector2(0.0f, 0.0f), Vector2(399.0f / 7.0f, 64.0f), 7);

		/// <summary>
		///
		/// </summary>
		at = GetOwner()->GetComponent<Animator>();
		at->CompleteEvent(L"Jump") = std::bind(&PlayerScript::Complete, this);
	}

	void PlayerScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::LEFT))
		{
			pos.x -= 1.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		else if (Input::GetKey(eKeyCode::RIGHT))
		{
			pos.x += 1.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKeyDown(eKeyCode::RIGHT))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Walk", true);
		}

		if (Input::GetKeyUp(eKeyCode::RIGHT))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Idle", true);
		}

		else if (Input::GetKey(eKeyCode::DOWN))
		{
			pos.y -= 1.0f * Time::DeltaTime();
			tr->SetPosition(pos);

			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Walk", true);
		}

		else if (Input::GetKey(eKeyCode::UP))
		{
			pos.y += 1.0f * Time::DeltaTime();
			tr->SetPosition(pos);

			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Walk", true);
		}

		//if (Input::GetKey(eKeyCode::LSHIFT))
		//{
		//	Animator* at = this->GetOwner()->GetComponent<Animator>();
		//	at->PlayAnimation(L"Run", true);
		//}

		if (Input::GetKeyDown(eKeyCode::LSHIFT))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Run", true);
		}

		if (Input::GetKeyUp(eKeyCode::LSHIFT))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Idle", true);
		}

		if (Input::GetKeyDown(eKeyCode::SPACE))
		{
			Animator* at = this->GetOwner()->GetComponent<Animator>();
			at->PlayAnimation(L"Jump", true);
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
		}
	}

	void PlayerScript::Complete()
	{
		Animator* at = this->GetOwner()->GetComponent<Animator>();
		at->PlayAnimation(L"Idle", true);
	}
}
