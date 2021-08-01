#include "pch.h"
#include "DeviceContext.h"

using namespace ING::Engine;


DeviceContext::DeviceContext(Graphics* graphics, ID3D11DeviceContext* deviceContext) {
	this->graphics = graphics;
	this->d3dDeviceContext = deviceContext;
}


DeviceContext::~DeviceContext() {

}



void DeviceContext::ClearRenderTargetView(float color[4]) {
	d3dDeviceContext->ClearRenderTargetView(graphics->swapChain->renderTargetView,color);
}

void DeviceContext::ClearRenderTargetView(ID3D11RenderTargetView* renderTargetView,float color[4]) {
	d3dDeviceContext->ClearRenderTargetView(renderTargetView, color);

}





void DeviceContext::SetShader(Shader* shader) {

}