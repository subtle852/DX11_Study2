#include "yaRenderer.h"
#include "yaResources.h"
#include "yaTexture.h"
#include "yaMaterial.h"



namespace renderer
{
	using namespace ya;
	using namespace ya::graphics;
	Vertex vertexes[4] = {};
	ya::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[(UINT)eSamplerType::End] = {};

	//
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBSType::End] = {};
	

	//
	std::vector<ya::Camera*> cameras = {};

	void SetupState()
	{
#pragma region InputLayout
		// Input layout ���� ���� ������ �Ѱ�����Ѵ�.
		D3D11_INPUT_ELEMENT_DESC arrLayout[3] = {};

		arrLayout[0].AlignedByteOffset = 0;
		arrLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		arrLayout[0].InputSlot = 0;
		arrLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[0].SemanticName = "POSITION";
		arrLayout[0].SemanticIndex = 0;

		arrLayout[1].AlignedByteOffset = 12;
		arrLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		arrLayout[1].InputSlot = 0;
		arrLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[1].SemanticName = "COLOR";
		arrLayout[1].SemanticIndex = 0;

		arrLayout[2].AlignedByteOffset = 28;
		arrLayout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
		arrLayout[2].InputSlot = 0;
		arrLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[2].SemanticName = "TEXCOORD";
		arrLayout[2].SemanticIndex = 0;

		std::shared_ptr<Shader> shader = ya::Resources::Find<Shader>(L"TriangleShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

		shader = ya::Resources::Find<Shader>(L"SpriteShader");
		ya::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());
#pragma endregion
#pragma region Sampler State
		//Sampler State
		D3D11_SAMPLER_DESC samplerDesc = {};
		samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		GetDevice()->CreateSamplerState(&samplerDesc, samplerState[(UINT)eSamplerType::Point].GetAddressOf());
		GetDevice()->BindSampler(eShaderStage::PS, 0, samplerState[(UINT)eSamplerType::Point].GetAddressOf());

		samplerDesc.Filter = D3D11_FILTER_ANISOTROPIC;
		GetDevice()->CreateSamplerState(&samplerDesc, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
		GetDevice()->BindSampler(eShaderStage::PS, 1, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
#pragma endregion
#pragma region Rasterizer State
		D3D11_RASTERIZER_DESC rasterizerDesc = {};
		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_BACK;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::SolidBack].GetAddressOf());

		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_FRONT;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::SolidFront].GetAddressOf());

		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::SolidNone].GetAddressOf());

		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_WIREFRAME;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::WireframeNone].GetAddressOf());
#pragma endregion
#pragma region Depth Stencil State
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc = {};

		//less
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::Less].GetAddressOf());

		//Greater
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_GREATER;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::Greater].GetAddressOf());

		//No Write
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::NoWrite].GetAddressOf());

		//None
		depthStencilDesc.DepthEnable = false;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::None].GetAddressOf());
#pragma endregion
#pragma region Blend State
		D3D11_BLEND_DESC blendDesc = {};
		
		//default
		blendStates[(UINT)eBSType::Default] = nullptr;
		
		// Alpha Blend
		blendDesc.AlphaToCoverageEnable = false;
		blendDesc.IndependentBlendEnable = false;
		blendDesc.RenderTarget[0].BlendEnable = true;
		blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

		GetDevice()->CreateBlendState(&blendDesc
			, blendStates[(UINT)eBSType::AlphaBlend].GetAddressOf());

		// one one
		blendDesc.AlphaToCoverageEnable = false;
		blendDesc.IndependentBlendEnable = false;

		blendDesc.RenderTarget[0].BlendEnable = true;
		blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		GetDevice()->CreateBlendState(&blendDesc
			, blendStates[(UINT)eBSType::OneOne].GetAddressOf());

#pragma endregion


	}

	void LoadBuffer()
	{
		// Vertex Buffer - 1:1 ratio
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		Resources::Insert(L"RectMesh", mesh);

		mesh->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);

		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Constant Buffer
		constantBuffer[(UINT)eCBType::Transform] = new ConstantBuffer(eCBType::Transform);
		constantBuffer[(UINT)eCBType::Transform]->Create(sizeof(TransformCB));
	}

	void LoadShader()
	{
		std::shared_ptr<Shader> shader = std::make_shared<Shader>();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
		ya::Resources::Insert(L"TriangleShader", shader);

		std::shared_ptr<Shader> spriteShader = std::make_shared<Shader>();
		spriteShader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		spriteShader->Create(eShaderStage::PS, L"SpritePS.hlsl", "main");
		ya::Resources::Insert(L"SpriteShader", spriteShader);

		#pragma region SET TEXTURE
		//////////////////////////////////////////////////////////// TITLE
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			spriteMaterial->SetRenderingMode(eRenderingMode::Transparent);// eRenderingMode ����
			Resources::Insert(L"SpriteMaterial_BG_TITLE_01", spriteMaterial);
		}
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_TITLE_02", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_02.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_BG_TITLE_02", spriteMaterial);
		}

		//////////////////////////////////////////////////////////// MAIN
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_MAIN_01", L"..\\Resources\\SCENE\\02_MAIN\\BG_MAIN_01.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_BG_MAIN_01", spriteMaterial);
		}
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_MAIN_02", L"..\\Resources\\SCENE\\02_MAIN\\\\BG_MAIN_02.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_BG_MAIN_02", spriteMaterial);
		}

		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_CHAR", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_CHAR.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_CHAR", spriteMaterial);
		}
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_ENTER", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_ENTER.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_ENTER", spriteMaterial);
		}
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_MENU", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_MENU.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			//spriteMaterial->SetRenderingMode(eRenderingMode::Transparent);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_MENU", spriteMaterial);
		}
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_MENU_BAR", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_MENU_BAR.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			//spriteMaterial->SetRenderingMode(eRenderingMode::Transparent);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_MENU_BAR", spriteMaterial);
		}

		//////////////////////////////////////////////////////////// SELECT
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_SELECT_CURTAIN", L"..\\Resources\\SCENE\\03_SELECT\\BG_SELECT_CURTAIN.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_BG_SELECT_CURTAIN", spriteMaterial);
		}

		//////////////////////////////////////////////////////////// TOWN
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_TOWN_MAP", L"..\\Resources\\SCENE\\04_TOWN\\BG_TOWN_MAP.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_BG_TOWN_MAP", spriteMaterial);
		}

		//////////////////////////////////////////////////////////// STAGE 01
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"BG_STAGE01_01", L"..\\Resources\\SCENE\\STAGE01\\BG_STAGE01_01.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_BG_STAGE01_01", spriteMaterial);
		}

		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_STAGE01_STATE", L"..\\Resources\\SCENE\\STAGE01\\UI_STAGE01_STATE.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_UI_STAGE01_STATE", spriteMaterial);
		}

		

		#pragma endregion
	}

	void Initialize()
	{
		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);

		LoadBuffer();
		LoadShader();
		SetupState();

		std::shared_ptr<Texture> texture
			= Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");

		// TITLE
		texture
			= Resources::Load<Texture>(L"BG_TITLE_01", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_01.png");
		texture
			= Resources::Load<Texture>(L"BG_TITLE_02", L"..\\Resources\\SCENE\\01_TITLE\\BG_TITLE_02.png");
		
		// MAIN
		texture
			= Resources::Load<Texture>(L"BG_MAIN_01", L"..\\Resources\\SCENE\\02_MAIN\\BG_MAIN_01.png");
		texture
			= Resources::Load<Texture>(L"BG_MAIN_02", L"..\\Resources\\SCENE\\02_MAIN\\BG_MAIN_02.png");
		
		texture
			= Resources::Load<Texture>(L"UI_MAIN_CHAR", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_CHAR.png");
		texture
			= Resources::Load<Texture>(L"UI_MAIN_ENTER", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_ENTER.png");
		texture
			= Resources::Load<Texture>(L"UI_MAIN_MENU", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_MENU.png");
		texture
			= Resources::Load<Texture>(L"UI_MAIN_MENU_BAR", L"..\\Resources\\SCENE\\02_MAIN\\UI_MAIN_MENU_BAR.png");
		
		// SELECT
		texture
			= Resources::Load<Texture>(L"BG_SELECT_CURTAIN", L"..\\Resources\\SCENE\\03_SELECT\\BG_SELECT_CURTAIN.png");
		
		// TOWN
		texture
			= Resources::Load<Texture>(L"BG_TOWN_MAP", L"..\\Resources\\SCENE\\04_TOWN\\BG_TOWN_MAP.png");
		
		// STAGE 01
		texture
			= Resources::Load<Texture>(L"BG_STAGE01_BG", L"..\\Resources\\SCENE\\STAGE01\\BG_STAGE01_BG.png");
		texture
			= Resources::Load<Texture>(L"UI_STAGE01_STATE", L"..\\Resources\\SCENE\\STAGE01\\UI_STAGE01_STATE.png");


		texture->BindShader(eShaderStage::PS, 0);
	}

	void Render()
	{
		for (Camera* cam : cameras)
		{
			if (cam == nullptr)
				continue;

			cam->Render();
		}

		cameras.clear();
	}

	void Release()
	{
		for ( ConstantBuffer* buff : constantBuffer )
		{
			if (buff == nullptr)
				continue;

			delete buff;
			buff = nullptr;
		}
	}

}



