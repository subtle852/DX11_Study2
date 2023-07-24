#pragma once
#include "yaResource.h"
#include "yaGraphicDevice_Dx11.h"

namespace ya
{
	using namespace graphics;

	class Mesh : public Resource
	{
	public:
		Mesh();
		~Mesh();
		
		virtual HRESULT Load(const std::wstring& path) override;

		bool CreateVertexBuffer(void* data, UINT Count);
		bool CreateIndexBuffer(void* data, UINT Count);

		void BindBuffer(); //Buffer ���������ο� �����ش�.
		void Render();

		UINT GetIndexCount() { return mIndexCount; }

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mIndexBuffer;
		
		D3D11_BUFFER_DESC mVBDesc;
		D3D11_BUFFER_DESC mIBDesc;

		UINT mIndexCount;
	};
}
