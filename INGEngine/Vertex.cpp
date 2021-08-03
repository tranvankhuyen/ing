#include "pch.h"
#include "Graphics.h"
#include "InputLayoutDesc.h"

using namespace ING::Engine;

D3D11_INPUT_ELEMENT_DESC vertexInputLayoutDesc[3] = {
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "NORMAL",    0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

InputLayoutDesc Vertex::inputLayoutDesc = {
	vertexInputLayoutDesc,
	3
};