#ifndef RASTERIZERSTATE_H
#define RASTERIZERSTATE_H

#include <d3d11.h>

namespace ING{
	namespace Engine {
	
		struct RasterizerState {
		public:
			ID3D11RasterizerState* state;
		};
	}
}

#endif