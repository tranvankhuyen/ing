#ifndef RENDERLAYER_H
#define RENDERLAYER_H


#include "RenderSystem.h"
#include "RenderGroup.h"

namespace ING {
	namespace Engine {

		class RenderSystem;

		class RenderGroup;

		class RenderLayer {
		public:
			RenderLayer();
			~RenderLayer();

		public:
			RenderSystem* system;

		public:
			RenderGroup* CreateRenderGroup();

		};

	}
}

#endif