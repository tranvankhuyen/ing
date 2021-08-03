#include "pch.h"
#include "RenderGroup.h"

using namespace ING::Engine;


RenderGroup::RenderGroup() {

}


RenderGroup::~RenderGroup() {

}


void RenderGroup::Add(Renderer* renderer) {
	if (headRenderer == nullptr) {
		headRenderer = renderer;
		tailRenderer = renderer;
	}
	else {
		tailRenderer->next = renderer;
		renderer->prev = tailRenderer;
		tailRenderer = renderer;
	}
}


void RenderGroup::Remove(Renderer* renderer) {

	if (renderer->next != nullptr) {
		renderer->next->prev = renderer->prev;
	}
	else {
		tailRenderer = renderer->prev;
	}

	if (renderer->prev != nullptr) {
		renderer->prev->next = renderer->next;
	}
	else {
		headRenderer = renderer->next;
	}

}
