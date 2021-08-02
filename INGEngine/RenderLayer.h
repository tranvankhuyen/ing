#ifndef RENDERLAYER_H
#define RENDERLAYER_H

#include "INGEngine.h"
#include <vector>

namespace ING{
	namespace Engine {
		
		class Renderer;
	
		class RenderSystem;

		class RenderLayer {
		public:
			RenderLayer();
			~RenderLayer();
			
		public:
			RenderSystem* system;

		};
	
	}
}

#endif