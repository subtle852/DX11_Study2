#pragma once
#include <yaScene.h>

namespace ya
{
	class MainScene : public Scene
	{
	public:
		MainScene();
		virtual ~MainScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		int mMainEnterCount = 0;

		GameObject* mBG_01;
		GameObject* mBG_02;
	};
}