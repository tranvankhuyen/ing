#ifndef GBUFFER_H
#define GBUFFER_H

#include <d3d11.h>

namespace ING {
	namespace Engine {

		struct GBuffer {
			ID3D11Buffer* vertexBuffer;
			ID3D11Buffer* indicesBuffer;
		};

	}
}

#endif