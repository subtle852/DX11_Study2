#pragma once
#include "yaScene.h"


namespace ya
{
	class TownScene : public Scene
	{
	public:
		TownScene();
		virtual ~TownScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		GameObject* mBG_01;
	};
}