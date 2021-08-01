#ifndef RESOURCES_H
#define RESOURCES_H

#include "INGEngine.h"
#include "Mesh.h"

namespace ING {
	namespace Engine {
		


		class INGEngine;

		class Mesh;

		struct MeshData;

		class Resources {
		public:
			Resources(INGEngine* INGEngine);
			~Resources();
		
		public:
			INGEngine* INGEngine;

		public:
			MeshData* ImportMeshData_DemoFile(std::string path);
			Mesh* ImportMesh_DemoFile(std::string path);
		
		};

	}
}

#endif