#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

#include "INGEngine.h"
#include <d3d11.h>

namespace ING {
	namespace Engine {

		class Graphics;

		class SwapChain {
		public:
			SwapChain(Graphics* graphics);
			~SwapChain();
		
		public:
			Graphics* graphics;

		public:
			ID3D11RenderTargetView* renderTargetView;
			

		public:
			IDXGISwapChain* dxgiSwapChain;

		public:
			bool Init();


		public:
			void Resize(UINT width, UINT height);
			void Present();
		
		};

	}
}

#endif