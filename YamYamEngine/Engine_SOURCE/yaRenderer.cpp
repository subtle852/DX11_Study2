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
		// Input layout 정점 구조 정보를 넘겨줘야한다.
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

		// Vertex Buffer - 해당 Texture 가져와서 ratio에 맞춘 Vertex Buffer 생성 - BG Basic
		std::shared_ptr<Texture> texture
			= Resources::Load<Texture>(L"TITLE_01", L"..\\Resources\\BG\\01_TITLE\\TITLE_01.jpg");

		float width = texture.get()->GetImageSizeWidth();
		float height = texture.get()->GetImageSizeHeight();
		float ratioOfwidth = 0.5f;
		float ratioOfheight = height / width * ratioOfwidth;
		std::shared_ptr<Mesh> mesh2 = std::make_shared<Mesh>();
		Resources::Insert(L"BGBasicMesh", mesh2);

		vertexes[0].pos = Vector3(-ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].pos = Vector3(ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].pos = Vector3(ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].pos = Vector3(-ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);

		mesh2->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes2 = {};
		indexes2.push_back(0);
		indexes2.push_back(1);
		indexes2.push_back(2);

		indexes2.push_back(0);
		indexes2.push_back(2);
		indexes2.push_back(3);
		mesh2->CreateIndexBuffer(indexes2.data(), indexes2.size());

		// Vertex Buffer - BG Town
		texture = Resources::Load<Texture>(L"TOWN", L"..\\Resources\\BG\\04_TOWN\\TOWN.jpg");

		width = texture.get()->GetImageSizeWidth();
		height = texture.get()->GetImageSizeHeight();
		ratioOfwidth = 0.5f;
		ratioOfheight = height / width * ratioOfwidth;
		std::shared_ptr<Mesh> mesh3 = std::make_shared<Mesh>();
		Resources::Insert(L"BGTownMesh", mesh3);

		vertexes[0].pos = Vector3(-ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].pos = Vector3(ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].pos = Vector3(ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].pos = Vector3(-ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);

		mesh3->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes3 = {};
		indexes3.push_back(0);
		indexes3.push_back(1);
		indexes3.push_back(2);

		indexes3.push_back(0);
		indexes3.push_back(2);
		indexes3.push_back(3);
		mesh3->CreateIndexBuffer(indexes3.data(), indexes3.size());

		// Vertex Buffer - BG Stage01
		texture = Resources::Load<Texture>(L"STAGE01_BG", L"..\\Resources\\BG\\STAGE01\\STAGE01_BG.png");

		width = texture.get()->GetImageSizeWidth();
		height = texture.get()->GetImageSizeHeight();
		ratioOfwidth = 0.5f;
		ratioOfheight = height / width * ratioOfwidth;
		std::shared_ptr<Mesh> mesh4 = std::make_shared<Mesh>();
		Resources::Insert(L"BGStage01Mesh", mesh4);

		vertexes[0].pos = Vector3(-ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].pos = Vector3(ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].pos = Vector3(ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].pos = Vector3(-ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);

		mesh4->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes4 = {};
		indexes4.push_back(0);
		indexes4.push_back(1);
		indexes4.push_back(2);

		indexes4.push_back(0);
		indexes4.push_back(2);
		indexes4.push_back(3);
		mesh4->CreateIndexBuffer(indexes4.data(), indexes4.size());

		// Vertex Buffer - UI State
		texture = Resources::Load<Texture>(L"UI_STATE", L"..\\Resources\\UI\\UI_STATE.png");

		width = texture.get()->GetImageSizeWidth();
		height = texture.get()->GetImageSizeHeight();
		ratioOfwidth = 0.5f;
		ratioOfheight = height / width * ratioOfwidth;
		std::shared_ptr<Mesh> mesh5 = std::make_shared<Mesh>();
		Resources::Insert(L"Mesh_UI_STATE", mesh5);

		vertexes[0].pos = Vector3(-ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].pos = Vector3(ratioOfwidth, ratioOfheight, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].pos = Vector3(ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].pos = Vector3(-ratioOfwidth, -ratioOfheight, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);

		mesh5->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes5 = {};
		indexes5.push_back(0);
		indexes5.push_back(1);
		indexes5.push_back(2);

		indexes5.push_back(0);
		indexes5.push_back(2);
		indexes5.push_back(3);
		mesh5->CreateIndexBuffer(indexes5.data(), indexes5.size());

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
		// BG -TITLE
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"TITLE_01", L"..\\Resources\\BG\\01_TITLE\\TITLE_01.jpg");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			spriteMaterial->SetRenderingMode(eRenderingMode::Transparent);// eRenderingMode 설정
			Resources::Insert(L"SpriteMaterial_TITLE01", spriteMaterial);
		}
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"TITLE_02", L"..\\Resources\\BG\\01_TITLE\\TITLE_02.jpg");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_TITLE02", spriteMaterial);
		}

		// BG -MAIN
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"MAIN_01", L"..\\Resources\\BG\\02_MAIN\\MAIN_01.jpg");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_MAIN_01", spriteMaterial);
		}
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"MAIN_02", L"..\\Resources\\BG\\02_MAIN\\MAIN_02.jpg");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_MAIN_02", spriteMaterial);
		}

		// BG -SELECT
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"SELECT", L"..\\Resources\\BG\\03_SELECT\\CURTAIN.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_SELECT", spriteMaterial);
		}

		// BG - TOWN
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"TOWN", L"..\\Resources\\BG\\04_TOWN\\TOWN.jpg");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_TOWN", spriteMaterial);
		}

		// BG -STAGE 01
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"STAGE01_BG", L"..\\Resources\\BG\\STAGE01\\STAGE01_BG.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_STAGE01_BG", spriteMaterial);
		}

		// UI - STATE
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_STATE", L"..\\Resources\\UI\\UI_STATE.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_UI_STATE", spriteMaterial);
		}

		// UI - MAIN_ENTER
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_ENTER", L"..\\Resources\\UI\\UI_MAIN_ENTER.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_ENTER", spriteMaterial);
		}

		// UI - MAIN_SELECT_BAR
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_SELECT_BAR", L"..\\Resources\\UI\\UI_MAIN_SELECT_BAR.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			//spriteMaterial->SetRenderingMode(eRenderingMode::Transparent);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_SELECT_BAR", spriteMaterial);
		}

		// UI - MAIN_SELECT
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_SELECT", L"..\\Resources\\UI\\UI_MAIN_SELECT.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			//spriteMaterial->SetRenderingMode(eRenderingMode::Transparent);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_SELECT", spriteMaterial);
		}

		// UI - MAIN_CHARACTER
		{
			std::shared_ptr<Texture> texture
				= Resources::Load<Texture>(L"UI_MAIN_CHAR", L"..\\Resources\\UI\\UI_MAIN_CHAR.png");
			std::shared_ptr<Material> spriteMaterial = std::make_shared<Material>();
			spriteMaterial->SetShader(spriteShader);
			spriteMaterial->SetTexture(texture);
			Resources::Insert(L"SpriteMaterial_UI_MAIN_CHAR", spriteMaterial);
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

		//vertexes[0].pos = Vector3(-3.2f, 1.75f, 0.0f);
		//vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		//vertexes[0].uv = Vector2(0.0f, 0.0f);

		//vertexes[1].pos = Vector3(3.2f, 1.75f, 0.0f);
		//vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		//vertexes[1].uv = Vector2(1.0f, 0.0f);

		//vertexes[2].pos = Vector3(3.2f, -1.75f, 0.0f);
		//vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		//vertexes[2].uv = Vector2(1.0f, 1.0f);

		//vertexes[3].pos = Vector3(-3.2f, -1.75f, 0.0f);
		//vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		//vertexes[3].uv = Vector2(0.0f, 1.0f);

		LoadBuffer();
		LoadShader();
		SetupState();

		std::shared_ptr<Texture> texture
			= Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");

		texture
			= Resources::Load<Texture>(L"TITLE_01", L"..\\Resources\\BG\\01_TITLE\\TITLE_01.jpg");
		texture
			= Resources::Load<Texture>(L"TITLE_02", L"..\\Resources\\BG\\01_TITLE\\TITLE_02.jpg");
		texture
			= Resources::Load<Texture>(L"MAIN_01", L"..\\Resources\\BG\\02_MAIN\\MAIN_01.jpg");
		texture
			= Resources::Load<Texture>(L"MAIN_02", L"..\\Resources\\BG\\02_MAIN\\MAIN_02.jpg");
		texture
			= Resources::Load<Texture>(L"SELECT", L"..\\Resources\\BG\\03_SELECT\\CURTAIN.jpg");
		texture
			= Resources::Load<Texture>(L"TOWN", L"..\\Resources\\BG\\04_TOWN\\TOWN.jpg");
		texture
			= Resources::Load<Texture>(L"STAGE01_BG", L"..\\Resources\\BG\\STAGE01\\STAGE01_BG.jpg");
		
		texture
			= Resources::Load<Texture>(L"UI_STATE", L"..\\Resources\\UI\\UI_STATE.png");
		texture
			= Resources::Load<Texture>(L"UI_MAIN_ENTER", L"..\\Resources\\UI\\UI_MAIN_ENTER.png");
		texture
			= Resources::Load<Texture>(L"UI_MAIN_SELECT_BAR", L"..\\Resources\\UI\\UI_MAIN_SELECT_BAR.png");
		texture
			= Resources::Load<Texture>(L"UI_MAIN_SELECT", L"..\\Resources\\UI\\UI_MAIN_SELECT.jpg");
		texture
			= Resources::Load<Texture>(L"UI_MAIN_CHAR", L"..\\Resources\\UI\\UI_MAIN_CHAR.png");


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



