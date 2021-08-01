#include "pch.h"
#include "Entity.h"
#include "EntitiesSystem.h"

using namespace ING::Engine;


Entity::Entity() {
	components.resize(0);
	isActive = true;
}

Entity::~Entity() {

}





#pragma region Events

void Entity::OnFixedUpdate() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnFixedUpdate();
	}
}

void Entity::OnSetup() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnSetup();
	}
}

void Entity::OnStart() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnStart();
	}
}

void Entity::OnPreUpdate() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnPreUpdate();
	}
}

void Entity::OnUpdate() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnUpdate();
	}

}

void Entity::OnLateUpdate() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnLateUpdate();
	}
}

void Entity::OnPreRender() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnPreRender();
	}
}

void Entity::OnRender() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnRender();
	}
}

void Entity::OnAfterRender() {
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->OnAfterRender();
	}

}

#pragma endregion Events


