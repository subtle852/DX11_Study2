#include "yaGameObject.h"
#include "yaRenderer.h"
#include "yaGraphicDevice_Dx11.h"

namespace ya
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
	}

	void GameObject::Update()
	{
		// �� ������ ����



		// ����

	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render()
	{
		//������۷� ��ġ���� ũ������, ����, ������Ʈ ������Ѵ�.

		//renderer::mesh->BindBuffer();
		//renderer::shader->Binds();
		//graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
