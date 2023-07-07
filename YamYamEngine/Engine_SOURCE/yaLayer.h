#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Layer
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		void AddGameObject(GameObject* gameObj);
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }
		
	private:
		std::vector<GameObject*> mGameObjects;
	};
}
