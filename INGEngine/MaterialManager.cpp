#include "pch.h"
#include "MaterialManager.h"

using namespace ING::Engine;


MaterialManager::MaterialManager(Graphics* graphics) {

}

MaterialManager::~MaterialManager() {

}


Material* MaterialManager::CreateMaterial(Shader* shader) {
	Material* result = new Material();
	result->manager = this;
	result->shader = shader;
	return result;
}