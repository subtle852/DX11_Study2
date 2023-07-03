#pragma once
#include "..\Engine_SOURCE\yaScene.h"

namespace ya
{
	class MainScene : public Scene
	{
		enum class SelectNumber
		{
			StoryMode,
			NetworkGame,
			ExtraGameModex,
			UbisoftConnect,
			Achievements,
			Leaderboards,
			HelpNOptions,
			ExitGame,
		};

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

		GameObject* mBG_01 = nullptr;
		GameObject* mBG_02 = nullptr;

		GameObject* mUI_ENTER = nullptr;
		bool mUI_ENTER_SizeState = true;// false 감소, true 증가

		GameObject* mUI_SELECT_BAR = nullptr;
		GameObject* mUI_SELECT = nullptr;

		GameObject* mUI_CHAR = nullptr;
		bool mUI_CHAR_SizeState = true;// false 감소, true 증가

		int mSelectNumber = 0;
	};
}