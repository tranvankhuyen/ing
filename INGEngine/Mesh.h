#ifndef MESH_H
#define MESH_H

#include "INGEngine.h"
#include "Vertex.h"
#include <d3d11.h>
#include <vector>

namespace ING {
	namespace Engine {

		class Graphics;

		struct MeshBuffer {
			ID3D11Buffer* vertexBuffer;
			ID3D11Buffer* indicesBuffer;
		};

		struct MeshData {
			std::vector<Vertex> vertices;
			std::vector<UINT> indices;
		};

		class Mesh {
		public:
			Mesh();
			~Mesh();

		public:
			MeshBuffer* buffer;
			MeshData* data;

		public:
			Graphics* graphics;

		public:
			void BuildBuffer();
		};

	}
}

#endif