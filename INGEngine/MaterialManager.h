#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include "INGEngine.h"
#include "Material.h"

namespace ING {
	namespace Engine {

		class Graphics;

		class Material;

		class Shader;

		class MaterialManager {
		public:
			MaterialManager(Graphics* graphics);
			~MaterialManager();

		public:
			Graphics* graphics;

		public:
			Material* CreateMaterial(Shader* shader);

		};

	}
}

#endif