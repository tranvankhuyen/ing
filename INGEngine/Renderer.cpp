#include "pch.h"
#include "Renderer.h"
#include "RenderSystem.h"

using namespace ING::Engine;


Renderer::Renderer() {

}


Renderer::~Renderer() {

}




Material* Renderer::GetMaterial() {
	return this->material;
}


Mesh* Renderer::GetMesh() {
	return this->mesh;
}


RenderState* Renderer::GetRenderState() {
	return this->renderState;
}



void Renderer::SetMaterial(Material* mat) {
	this->material = mat;
}

void Renderer::SetMesh(Mesh* mesh) {
	this->mesh = mesh;
}

void Renderer::SetRenderState(RenderState* rState) {
	this->renderState=rState;
}