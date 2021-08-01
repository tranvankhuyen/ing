#include "pch.h"
#include "Graphics.h"
#include <d3dcompiler.h>

using namespace ING::Engine;

Graphics::Graphics(ING::Engine::INGEngine* INGEngine) {
	this->INGEngine = INGEngine;
}

Graphics::~Graphics() {

}




bool Graphics::InitDirectX() {
	D3D_DRIVER_TYPE driver_types[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT num_driver_types = ARRAYSIZE(driver_types);

	D3D_FEATURE_LEVEL feature_levels[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};
	UINT num_feature_levels = ARRAYSIZE(feature_levels);

	HRESULT res = 0;
	ID3D11DeviceContext* m_imm_context;

	for (UINT driver_type_index = 0; driver_type_index < num_driver_types;)
	{
		res = D3D11CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels,
			num_feature_levels, D3D11_SDK_VERSION, &d3dDevice, &featureLevel, &m_imm_context);
		if (SUCCEEDED(res))
			break;
		++driver_type_index;
	}
	if (FAILED(res))
	{
		return false;
	}

	deviceContext = new DeviceContext(this,m_imm_context);

	d3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);
	dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter);
	dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory);


	D3D11_TEXTURE2D_DESC descDepth;
	descDepth.Width = INGEngine->window->clientWidth;
	descDepth.Height = INGEngine->window->clientHeight;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;

	d3dDevice->CreateTexture2D(&descDepth, 0, &depthStencilBuffer);


	HRESULT hrr = d3dDevice->CreateDepthStencilView(depthStencilBuffer, 0, &depthStencilView);

	if (FAILED(hrr)) {
		return false;
	}

	swapChain = new SwapChain(this);

	renderSystem = new RenderSystem(this);

	shaderCompiler = new ShaderCompiler(this);

	materialManager = new MaterialManager(this);

	return true;
}


bool Graphics::Init() {
	if (!InitDirectX()) {
		return false;
	}
	if (!swapChain->Init()) {
		return false;
	}
	if (!shaderCompiler->Init()) {
		return false;
	}
	return true;
}


Shader* Graphics::CreateShader() {
	Shader* result = new Shader();

	return result;
}


Shader* Graphics::CreateShaderFromFile(LPCWSTR srcPath) {

	Shader* shader = CreateShader();

	ID3DBlob* m_vsblob = nullptr;
	ID3DBlob* m_psblob = nullptr;
	ID3DBlob* errblob = nullptr;

	ID3D11VertexShader* m_vs = nullptr;
	ID3D11PixelShader* m_ps = nullptr;

	HRESULT hr = D3DCompileFromFile(srcPath, nullptr, nullptr, "vsmain", "vs_5_0", NULL, NULL, &m_vsblob, &errblob);
	HRESULT hr2 = D3DCompileFromFile(srcPath, nullptr, nullptr, "psmain", "ps_5_0", NULL, NULL, &m_psblob, &errblob);

	if (errblob != 0) {
		MessageBoxA(0, (char*)errblob->GetBufferPointer(), 0, 0);
	}
	
	if (FAILED(hr)) {
		return nullptr;
	}

	if (FAILED(hr2)) {
		return nullptr;
	}

	d3dDevice->CreateVertexShader(m_vsblob->GetBufferPointer(), m_vsblob->GetBufferSize(), nullptr, &m_vs);
	d3dDevice->CreatePixelShader(m_psblob->GetBufferPointer(), m_psblob->GetBufferSize(), nullptr, &m_ps);

	shader->vertexShader = m_vs;
	shader->pixelShader = m_ps;

	shader->pvsblob = m_vsblob;
	shader->ppsblob = m_psblob;

	return shader;
}




Mesh* Graphics::CreateMesh() {
	Mesh* mesh = new Mesh();
	mesh->graphics = this;
	return mesh;
}



RenderState* Graphics::CreateRenderState() {
	RenderState* state = new RenderState();
	state->graphics = this;
	return state;
}