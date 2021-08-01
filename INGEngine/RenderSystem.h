#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "Graphics.h"
#include "Renderer.h"

namespace ING {
	namespace Engine {
		
		class Graphics;

		class Renderer;

		class RenderSystem {
		public:
			RenderSystem(Graphics* graphics);
			~RenderSystem();

		public:
			Graphics* graphics;

		public:
			Renderer* CreateRenderer();

		};

	}
}

#endif