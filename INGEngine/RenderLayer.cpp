#include "pch.h"
#include "RenderLayer.h"

using namespace ING::Engine;

RenderLayer::RenderLayer() {

}

RenderLayer::~RenderLayer() {

}


RenderGroup* RenderLayer::CreateRenderGroup() {
	RenderGroup* group = new RenderGroup();
	group->layer = this;
	return group;
}