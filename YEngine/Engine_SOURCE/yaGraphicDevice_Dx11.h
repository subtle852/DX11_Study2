#pragma once
#include "YEngine.h"

#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

namespace ya::graphics
{
	class GraphicDevice_Dx11
	{
	public:
		GraphicDevice_Dx11();
		~GraphicDevice_Dx11();

	private:
		// ���� �׷���ī�� �ϵ���� ��ü
		Microsoft::WRL::ComPtr<ID3D11Device> mDevice; 
		

		//  dx11���� ���������� ����̽���ü ���������ʰ�
		// �̰�ü�� �̿��Ͽ� ����� ������.
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> mContext; 
		
		// ���������� �׷��� �ؽ�ó(��ȭ��)
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mRenderTarget;

		// ����Ÿ�ٿ� ������������ �ʰ� ����Ÿ�ٺ並 ���ؼ� �����Ѵ�.
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRenderTargetView;

		// ���̹���
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mDepthStencilBuffer;

		// ���̹��ۿ� �����Ҽ� �ִ� ��
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDepthStencilView;

		// ������۸� �۾��� �������ִ� swapChain
		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
	};
}

// ����� �λ��� �����Ͻʴϱ�?
// are you satisfied all your life?
// are you haapy?