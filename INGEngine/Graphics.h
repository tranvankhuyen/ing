#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "INGEngine.h"

#include "DeviceContext.h"
#include "SwapChain.h"
#include "RenderSystem.h"
#include "ShaderCompiler.h"
#include "MaterialManager.h"
#include "Mesh.h"
#include "Shader.h"
#include "Vertex.h"
#include "RenderState.h"

#include <iostream>

#include <d3d11.h>

namespace ING {
	namespace Engine {

		class INGEngine;

		class DeviceContext;
		
		class SwapChain;

		class RenderSystem;

		class ShaderCompiler;

		class MaterialManager;

		class Shader;

		class Mesh;

		class RenderState;

		class Graphics
		{
		public:
			Graphics(INGEngine* INGEngine);
			~Graphics();

		public:
			INGEngine* INGEngine;

		public:
			bool Init();


#pragma region DirectX
		private:
			bool InitDirectX();

		public:
			ID3D11Device* d3dDevice;
			D3D_FEATURE_LEVEL featureLevel;

		public:
			IDXGIDevice* dxgiDevice;
			IDXGIAdapter* dxgiAdapter;
			IDXGIFactory* dxgiFactory;

		public:
			ID3D11RenderTargetView* renderTargetView;

			ID3D11DepthStencilView* depthStencilView;
			ID3D11Texture2D* depthStencilBuffer;

#pragma endregion DirectX

		public:
			DeviceContext* deviceContext;
			SwapChain* swapChain;
			RenderSystem* renderSystem;
			ShaderCompiler* shaderCompiler;
			MaterialManager* materialManager;

		public:
			Shader* CreateShader();
			Shader* CreateShaderFromFile(LPCWSTR srcPath);
			

		public:
			Mesh* CreateMesh();

		public:
			RenderState* CreateRenderState();
		};


	}
}


#endif