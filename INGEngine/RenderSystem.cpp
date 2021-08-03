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


RenderGroup* RenderSystem::CreateRenderGroup() {
	RenderGroup* group = new RenderGroup();
	return group;
}



void RenderSystem::AddRenderLayer(RenderLayer* layer) {
	size_t size = layers.size();
	layers.resize(size+1);
	layers[size] = layer;
}


void RenderSystem::Render() {

}