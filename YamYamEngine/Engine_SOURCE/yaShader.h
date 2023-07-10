#pragma once
#include "yaResource.h"

#include "yaResource.h"
#include "yaGraphicDevice_Dx11.h"

namespace ya
{
	using namespace graphics;
	class Shader : public Resource
	{
	public:
		Shader();
		~Shader();

		virtual HRESULT Load(const std::wstring& path) override;

		bool Create(const eShaderStage stage, const std::wstring& fileName, const std::string& funcName);
		void Binds();

		ID3DBlob* GetVSCode()
		{
			return mVSBlob.Get();
		}
		ID3D11InputLayout* GetInputLayout()
		{
			return mInputLayout;
		}
		ID3D11InputLayout** GetInputLayoutAddressOf()
		{
			return &mInputLayout;
		}

		void SetRSState(eRSType type) { mRSType = type; }
		void SetDSState(eDSType type) { mDSType = type; }
		void SetBSState(eBSType type) { mBSType = type; }
		void SetTopology(D3D11_PRIMITIVE_TOPOLOGY topology) { mTopology = topology; }

	private:
		ID3D11InputLayout* mInputLayout;
		D3D11_PRIMITIVE_TOPOLOGY mTopology;

		Microsoft::WRL::ComPtr<ID3DBlob> mVSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mHSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mDSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mGSBlob;
		Microsoft::WRL::ComPtr<ID3DBlob> mPSBlob;

		Microsoft::WRL::ComPtr<ID3D11VertexShader> mVS;
		Microsoft::WRL::ComPtr<ID3D11HullShader> mHS;
		Microsoft::WRL::ComPtr<ID3D11DomainShader> mDS;
		Microsoft::WRL::ComPtr<ID3D11GeometryShader> mGS;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> mPS;

		eRSType mRSType;
		eDSType mDSType;
		eBSType mBSType;
	};
}


