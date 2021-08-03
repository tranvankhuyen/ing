#ifndef INPUTLAYOUTDESC
#define INPUTLAYOUTDESC

#include <d3d11.h>

namespace ING {
	namespace Engine {


		struct InputLayoutDesc {
			D3D11_INPUT_ELEMENT_DESC* layout;
			UINT elementsCount;
		};

	}
}

#endif