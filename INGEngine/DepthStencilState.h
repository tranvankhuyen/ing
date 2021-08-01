#ifndef DEPTHSTENCILSTATE_H
#define DEPTHSTENCILSTATE_H

#include <d3d11.h>

namespace ING {
	namespace Engine {

		struct DepthStencilState {
		public:
			ID3D11DepthStencilState* state;
		};
	}
}

#endif