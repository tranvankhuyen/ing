#ifndef SHADER_H
#define SHADER_H

#include <d3d11.h>
#include "InputLayoutDesc.h"

namespace ING {
	namespace Engine {

		class Graphics;

		class Shader {
		public:
			Shader();
			~Shader();

		public:
			Graphics* graphics;

		public:
			ID3DBlob* pvsblob;
			ID3DBlob* ppsblob;

			ID3D11VertexShader* vertexShader;
			ID3D11PixelShader* pixelShader;

		public:
			ID3D11InputLayout* inputLayout;
			InputLayoutDesc inputLayoutDesc;

		public:
			bool isCurrentShader;

		};

	}
}

#endif