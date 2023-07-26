#pragma once
#include "yaPlayer.h"

namespace ya
{
	class Ramona : public Player
	{
	public:
		Ramona();
		virtual ~Ramona();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		//ePlayerState GetRamonaState() { return mRamonaState; }
		//void SetRamonaState(ePlayerState state) { mRamonaState = state; }

	private:
		//ePlayerState mRamonaState = ePlayerState::R_Idle;

		float mHeart = 3.0f;
		float mHp = 100.0f;
		float mGp = 0.0f;
		float mCoin = 0.0f;
	};
}