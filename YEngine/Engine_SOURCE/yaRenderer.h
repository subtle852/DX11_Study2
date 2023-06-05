#pragma once
#include "YEngine.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaMesh.h"
#include "yaShader.h"

using namespace ya::math;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	//extern Vertex vertexes[];
	//extern ID3D11InputLayout* triangleLayout;
	//extern ID3D11Buffer* triangleBuffer;
	//extern ID3D11Buffer* triangleIdxBuffer;
	//extern ID3D11Buffer* triangleConstantBuffer;
	//extern ID3DBlob* errorBlob;
	//extern ID3DBlob* triangleVSBlob;
	//extern ID3D11VertexShader* triangleVSShader;
	//extern ID3DBlob* trianglePSBlob;
	//extern ID3D11PixelShader* trianglePSShader;

	extern Vertex vertexes[];
	extern ID3D11InputLayout* triangleLayout;
	extern ya::Mesh* mesh;
	extern ID3D11Buffer* triangleConstantBuffer;
	extern ya::Shader* shader;
	extern ID3D11PixelShader* trianglePSShader;

	void Initialize();
	void Release();
}