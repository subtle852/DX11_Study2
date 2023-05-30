#include "yaRenderer.h"

namespace ya::renderer
{
	Vertex vertexes[33] = {};

	// Input Layout (정점 정보, 형태)
	ID3D11InputLayout* triangleLayout = nullptr;

	// Vertex Buffer
	ID3D11Buffer* triangleBuffer = nullptr;

	// error blob
	ID3DBlob* errorBlob = nullptr;

	// Vertex Shader code -> Binary Code
	ID3DBlob* triangleVSBlob = nullptr;

	// Vertex Shader
	ID3D11VertexShader* triangleVSShader = nullptr;

	// Pixel Shader code -> Binary Code
	ID3DBlob* trianglePSBlob = nullptr;

	// Vertex Shader
	ID3D11PixelShader* trianglePSShader = nullptr;

	void SetupState()
	{

	}

	void LoadBuffer()
	{
		D3D11_BUFFER_DESC triangleDesc = {};
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleDesc.ByteWidth = sizeof(Vertex) * 33;
		triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		D3D11_SUBRESOURCE_DATA triangleData = {};
		triangleData.pSysMem = vertexes;
		ya::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);
	}

	void LoadShader()
	{
		ya::graphics::GetDevice()->CreateShader();
	}

	void Initialize()
	{
		vertexes[0].pos = Vector3(-0.5f, 0.7f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(-0.3f, 0.3f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(-0.7f, 0.3f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		// 삼각형 두개로 네모
		// 정점 6개
		vertexes[3].pos = Vector3(0.2f, 0.4f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[4].pos = Vector3(0.4f, 0.4f, 0.0f);
		vertexes[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[5].pos = Vector3(0.2f, 0.2f, 0.0f);
		vertexes[5].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[6].pos = vertexes[4].pos;
		vertexes[6].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[7].pos = Vector3(0.4f, 0.2f, 0.0f);
		vertexes[7].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[8].pos = vertexes[5].pos;
		vertexes[8].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		// 삼각형 두개로 마름모
		// 정점 6개
		vertexes[9].pos = Vector3(-0.7f, -0.5f, 0.0f);
		vertexes[9].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[10].pos = Vector3(-0.5f, -0.4f, 0.0f);
		vertexes[10].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[11].pos = Vector3(-0.5f, -0.6f, 0.0f);
		vertexes[11].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[12].pos = Vector3(-0.5f, -0.4f, 0.0f);
		vertexes[12].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[13].pos = Vector3(-0.3f, -0.5f, 0.0f);
		vertexes[13].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[14].pos = Vector3(-0.5f, -0.6f, 0.0f);
		vertexes[14].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//// 원 그리기
		//const double PI = 3.1415926;

		//// 각도
		//int degree = 80;
		//float radian = ((PI / 180) * (degree));
		//float r = 0.2f;

		//// 삼각함수 값 구하기
		//float x =  0.5f + r * cos(radian);
		//float y = -0.5f + r * sin(radian);

		//vertexes[15].pos = Vector3(0.5f, -0.3f, 0.0f);
		//vertexes[15].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		//vertexes[16].pos = Vector3(x, y, 0.0f);
		//vertexes[16].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		//vertexes[17].pos = Vector3(0.5f, -0.5f, 0.0f);
		//vertexes[17].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		const double PI = 3.1415926;
		int index = 15;
		for (int degree = 80; degree >= 40; )
		{
			float radian = ((PI / 180) * (degree));
			float r = 0.2f;

			float x = 0.5f + r * cos(radian);
			float y = -0.5f + r * sin(radian);


			vertexes[index].pos = Vector3(0.5f, -0.3f, 0.0f);
			vertexes[index].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
			index++;
			vertexes[index].pos = Vector3(x, y, 0.0f);
			vertexes[index].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
			index++;
			vertexes[index].pos = Vector3(0.5f, -0.5f, 0.0f);
			vertexes[index].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
			index++;

			degree -= 10;
		}

		SetupState();
		LoadBuffer();
		LoadShader();
	}
}



