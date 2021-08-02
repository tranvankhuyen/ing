#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "Graphics.h"
#include "Renderer.h"
#include "RenderLayer.h"

namespace ING {
	namespace Engine {
		
		class Graphics;

		class Renderer;

		class RenderLayer;

		class RenderSystem {
		public:
			RenderSystem(Graphics* graphics);
			~RenderSystem();

		public:
			Graphics* graphics;

		public:
			void Render();

		public:
			Renderer* CreateRenderer();
			RenderLayer* CreateRenderLayer();

		};

	}
}

#endif