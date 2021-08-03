#include "pch.h"
#include "RenderLayer.h"

using namespace ING::Engine;

RenderLayer::RenderLayer() {

}

RenderLayer::~RenderLayer() {

}



void RenderLayer::AddGroup(RenderGroup* group) {
	if (headGroup == nullptr) {
		headGroup = group;
		tailGroup = group;
	}
	else {
		tailGroup->next = group;
		group->prev = tailGroup;
		tailGroup = group;
	}
}


void RenderLayer::RemoveGroup(RenderGroup* group) {

	if (group->next != nullptr) {
		group->next->prev = group->prev;
	}
	else {
		tailGroup = group->prev;
	}

	if (group->prev != nullptr) {
		group->prev->next = group->next;
	}
	else {
		headGroup = group->next;
	}

}