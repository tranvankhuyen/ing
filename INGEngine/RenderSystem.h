#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "Graphics.h"
#include "Renderer.h"
#include "RenderLayer.h"
#include <vector>

namespace ING {
	namespace Engine {
		
		class Graphics;

		class Renderer;

		class RenderLayer;

		class Shader;

		class RenderSystem {
		public:
			RenderSystem(Graphics* graphics);
			~RenderSystem();

		public:
			Graphics* graphics;

		public:
			std::vector<RenderLayer*> layers;

		public:
			void AddRenderLayer(RenderLayer* layer);

		public:
			Renderer* CreateRenderer();
			RenderLayer* CreateRenderLayer();
			RenderGroup* CreateRenderGroup();

		public:
			Shader* currentShader;

		};

	}
}

#endif