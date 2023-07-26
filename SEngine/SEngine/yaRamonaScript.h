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

		void Complete();
		void SuperComplete();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		//void L_idle();
		//void R_idle();

		//void L_walk();
		//void R_walk();

		//void L_run();
		//void R_run();

		//void L_jump();
		//void R_jump();

		//void L_normalAttack();
		//void R_normalAttack();

		//void L_kick();
		//void R_kick();

		//void L_guard();
		//void R_guard();

		//void L_evade();
		//void R_evade();


	private:
		ePlayerState mRamonaState = ePlayerState::R_Idle;

	};
}