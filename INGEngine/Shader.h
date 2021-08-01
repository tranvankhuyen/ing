#ifndef SHADER_H
#define SHADER_H

#include "INGEngine.h"

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

			ID3D11InputLayout* pInputLayout;

		};

	}
}

#endif