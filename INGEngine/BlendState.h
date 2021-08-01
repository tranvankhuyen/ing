#ifndef BLENDSTATE_H
#define BLENDSTATE_H

#include <d3d11.h>

namespace ING {
	namespace Engine {

		struct BlendState {
		public:
			ID3D11BlendState* state;
		};
	}
}

#endif