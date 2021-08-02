#ifndef MESH_H
#define MESH_H

#include "INGEngine.h"
#include "Vertex.h"
#include <d3d11.h>
#include <vector>
#include "GBuffer.h"

namespace ING {
	namespace Engine {

		class Graphics;

		struct MeshData {
			std::vector<Vertex> vertices;
			std::vector<UINT> indices;
		};

		class Mesh {
		public:
			Mesh();
			~Mesh();

		public:
			GBuffer* gbuffer;
			MeshData* data;

		public:
			Graphics* graphics;

		public:
			void BuildGBuffer();
		};

	}
}

#endif