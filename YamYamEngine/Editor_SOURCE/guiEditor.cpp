#include "guiEditor.h"
#include "yaMesh.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaMaterial.h"
#include "yaGridScript.h"
#include "yaRenderer.h"

namespace gui
{
	using namespace ya::enums;
	std::vector<Widget*> Editor::mWidgets = {};
	std::vector<EditorObject*> Editor::mEditorObjects = {};
	std::vector<DebugObject*> Editor::mDebugObjects = {};

	void Editor::Initialize()
	{
		mDebugObjects.resize((UINT)eColliderType::End);

		std::shared_ptr<ya::Mesh> mesh
			= ya::Resources::Find<ya::Mesh>(L"DebugRect");
		std::shared_ptr<ya::Material> material
			= ya::Resources::Find<ya::Material>(L"DebugMaterial");

		mDebugObjects[(UINT)eColliderType::Rect] = new DebugObject();
		mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<ya::Transform>();
		ya::MeshRenderer* mr
			= mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<ya::MeshRenderer>();
		mr->SetMaterial(material);
		mr->SetMesh(mesh);


		EditorObject* grid = new EditorObject();
		grid->SetName(L"Grid");

		mr = grid->AddComponent<ya::MeshRenderer>();
		mr->SetMesh(ya::Resources::Find<ya::Mesh>(L"RectMesh"));
		mr->SetMaterial(ya::Resources::Find<ya::Material>(L"GridMaterial"));
		ya::GridScript* gridSc = grid->AddComponent<ya::GridScript>();
		gridSc->SetCamera(renderer::cameras[0]);

		mEditorObjects.push_back(grid);

	}
	void Editor::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Editor::Update()
	{


		for (EditorObject* obj : mEditorObjects)
		{
			obj->Update();
		}
	}
	void Editor::LateUpdate()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->LateUpdate();
		}
	}
	void Editor::Render()
	{
		//Microsoft::WRL::ComPtr<ID3D11DepthStencilState> ds
		//	= renderer::depthStencilStates[(UINT)ya::graphics::eDSType::Less];
		//ya::graphics::GetDevice()->BindDepthStencilState(ds.Get());

		for (EditorObject* obj : mEditorObjects)
		{
			obj->Render();
		}

		for (const ya::graphics::DebugMesh& mesh
			: renderer::debugMeshs)
		{
			DebugRender(mesh);
		}
	}
	void Editor::Release()
	{
	}

	void Editor::DebugRender(const ya::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];

		// ��ġ ũ�� ȸ�� ������ �޾ƿͼ�
		// �ش� ���ӿ�����Ʈ���� �׷��ָ�ȴ�.



		debugObj->Render();
	}
}
