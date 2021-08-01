#include "pch.h"
#include "RenderState.h"

using namespace ING::Engine;


RenderState::RenderState() {

}


RenderState::~RenderState() {

}


void RenderState::Set(RasterizerState* rasterizer, DepthStencilState* depthStencil, BlendState* blend) {
	this->rasterizer = rasterizer;
	this->depthStencil = depthStencil;
	this->blend = blend;
}