#ifndef VERTEX_H
#define VERTEX_H

#include "INGEngine.h"
#include <DirectXMath.h>
#include "InputLayoutDesc.h"

namespace ING {
	namespace Engine {


		struct Vertex {
			DirectX::XMFLOAT3 position;
			DirectX::XMFLOAT3 normal;
			DirectX::XMFLOAT2 texcoord;
			static InputLayoutDesc inputLayoutDesc;
		};


	}
}

#endif