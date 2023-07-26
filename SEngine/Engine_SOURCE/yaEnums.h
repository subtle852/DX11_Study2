#pragma once


namespace ya::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Collider2D,
		Particle,
		MeshRenderer,
		Animator,
		Script,
		Light,
		Camera,
		End,
	};

	enum class eLayerType
	{
		Grid,
		BG,
		Player,
		Monster,
		Light,
		UI,
		End = 16,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		Animation,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		End,
	};

	enum class eAnimationType : UINT
	{
		None,
		Front,
		Back,
	};

	enum class eLightType
	{
		Directional,
		Point,
		Spot,
		End,
	};

	enum class eDirection
	{
		L,
		R,
	};

	enum class ePlayerState
	{
		L_Idle,
		R_Idle,
		L_Walk,
		R_Walk,
		L_Run,
		R_Run,
		L_Jump,
		R_Jump,
		L_NormalAttack,
		R_NormalAttack,
		L_Kick,
		R_Kick,
		L_Guard,
		R_Guard,
		L_Evade,
		R_Evade,
	};
}