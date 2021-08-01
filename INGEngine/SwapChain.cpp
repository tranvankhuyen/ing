#include "pch.h"
#include "SwapChain.h"

using namespace ING::Engine;

SwapChain::SwapChain(Graphics* graphics) {
	this->graphics = graphics;
}

SwapChain::~SwapChain() {

}


bool SwapChain::Init() {


	ID3D11Device* device = graphics->d3dDevice;

	UINT clientWidth =  graphics->INGEngine->window->clientWidth;
	UINT clientHeight = graphics->INGEngine->window->clientHeight;
	HWND hwnd = graphics->INGEngine->window->hwnd;

	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.BufferCount = 1;
	desc.BufferDesc.Width = clientWidth;
	desc.BufferDesc.Height = clientHeight;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.BufferDesc.RefreshRate.Numerator = 60;
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = hwnd;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = TRUE;

	HRESULT hr = graphics->dxgiFactory->CreateSwapChain(device, &desc, &dxgiSwapChain);


	if (FAILED(hr))
	{
		return false;
	}

	ID3D11Texture2D* buffer = NULL;
	hr = dxgiSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

	if (FAILED(hr))
	{
		return false;
	}

	hr = device->CreateRenderTargetView(buffer, NULL, &renderTargetView);
	buffer->Release();


	if (FAILED(hr))
	{
		return false;
	}

	graphics->renderTargetView = renderTargetView;

	return true;
}


void SwapChain::Resize(UINT width, UINT height) {

}


void SwapChain::Present() {
	dxgiSwapChain->Present(0, 0);
}