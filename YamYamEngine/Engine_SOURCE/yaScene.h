#pragma once
#include "yaEntity.h"
#include "yaLayer.h"

namespace ya
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(eLayerType type, GameObject* gameObj);

	private:
		std::vector<Layer> mLayers;
	};
}
