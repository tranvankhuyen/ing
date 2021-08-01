#ifndef RENDERSTATE_H
#define RENDERSTATE_H

#include "INGEngine.h"
#include "RasterizerState.h"
#include "DepthStencilState.h"
#include "BlendState.h"

namespace ING {
	namespace Engine {


		class Graphics;

		class RenderState {
		public:
			RenderState();
			~RenderState();
		public:
			Graphics* graphics;

		public:
			RasterizerState* rasterizer;
			DepthStencilState* depthStencil;
			BlendState* blend;

		public:
			void Set(RasterizerState* rasterizer,DepthStencilState* depthStencil,BlendState* blend);

		};

	}
}

#endif