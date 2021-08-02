#ifndef INPUTLAYOUTDESC_H
#define INPUTLAYOUTDESC_H

#include <d3d11.h>
#include <vector>

namespace ING {
	namespace Engine {



		struct InputLayoutDesc {
			D3D11_INPUT_ELEMENT_DESC* layout;
			UINT elementsCount;
		};

	}
}

#endif