#pragma once

namespace ya::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Particle,
		MeshRenderer,
		Script,
		End,
	};

	enum class eLayerType
	{
		Player,
		Moster,
		Effect,
		UI,
		End,
	};
}