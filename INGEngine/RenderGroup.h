#ifndef RENDERGROUP_H
#define RENDERGROUP_H


#include "RenderLayer.h"

namespace ING {
	namespace Engine {

		class RenderLayer;

		class RenderGroup {
		public:
			RenderGroup();
			~RenderGroup();

		public:
			RenderLayer* layer;
		};

	}
}

#endif