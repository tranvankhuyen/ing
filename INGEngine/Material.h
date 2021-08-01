#ifndef MATERIAL_H
#define MATERIAL_H

#include "INGEngine.h"


namespace ING {
	namespace Engine {

		class Shader;

		class MaterialManager;

		class Material {
		public:
			Material();
			~Material();

		public:
			MaterialManager* manager;

		public:
			Shader* shader;

		};

	}
}

#endif