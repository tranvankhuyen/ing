#include "pch.h"
#include "RenderSystem.h"

using namespace ING::Engine;


RenderSystem::RenderSystem(Graphics* graphics) {
	this->graphics = graphics;
}

RenderSystem::~RenderSystem() {

}


Renderer* RenderSystem::CreateRenderer() {
	Renderer* renderer = new Renderer();
	renderer->system = this;
	return renderer;
}



RenderLayer* RenderSystem::CreateRenderLayer() {
	RenderLayer* renderLayer = new RenderLayer();
	renderLayer->system = this;
	return renderLayer;
}