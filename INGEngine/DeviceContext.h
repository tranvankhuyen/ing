#ifndef DEVICECONTEXT_H
#define DEVICECONTEXT_H

#include "INGEngine.h"
#include <d3d11.h>


namespace ING {
	namespace Engine {

		class Graphics;

		class Shader;

		class DeviceContext
		{
		public:
			DeviceContext(Graphics* graphics,ID3D11DeviceContext* deviceContext);
			~DeviceContext();

		public:
			Graphics* graphics;

#pragma region DirectX
		public:
			ID3D11DeviceContext* d3dDeviceContext;

#pragma endregion DirectX

		public:
			void ClearRenderTargetView(float color[4]);
			void ClearRenderTargetView(ID3D11RenderTargetView* renderTargetView, float color[4]);

		public:
			void SetShader(Shader* shader);

		};


	}
}

#endif