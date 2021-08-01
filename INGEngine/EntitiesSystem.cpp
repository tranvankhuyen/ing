#include "pch.h"
#include "EntitiesSystem.h"

using namespace ING::Engine;

EntitiesSystem::EntitiesSystem(ING::Engine::INGEngine* INGEngine) {
	this->INGEngine = INGEngine;
}

EntitiesSystem::~EntitiesSystem() {

}



#pragma region Events

void EntitiesSystem::OnFixedUpdate() {
	Entity* entity=headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if(entity->isActive)
				entity->OnFixedUpdate();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnSetup() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnSetup();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnStart() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnStart();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnPreUpdate() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnPreUpdate();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnUpdate() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnUpdate();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnLateUpdate() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnLateUpdate();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnPreRender() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnPreRender();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnRender() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnRender();
			entity = entity->next;
		}
	}
}

void EntitiesSystem::OnAfterRender() {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		for (size_t i = 0; i < entitiesCount; i++) {
			if (entity->isActive)
				entity->OnAfterRender();
			entity = entity->next;
		}
	}
}

#pragma endregion Events




void EntitiesSystem::AddEntity(Entity* entity) {
	if (headEntity==nullptr) {
		headEntity = entity;
		tailEntity = entity;
		entitiesCount = 1;
	}
	else {
		tailEntity->next = entity;
		entity->prev = tailEntity;
		tailEntity = entity;
		entitiesCount++;
	}
}

Entity* EntitiesSystem::CreateEntity() {
	Entity* entity = new Entity();
	entity->system = this;
	return entity;
}

void EntitiesSystem::RemoveEntity(Entity* entity) {
	entitiesCount--;
	if (entity->prev==nullptr) {
		headEntity = entity->next;
	}
	else {
		entity->prev->next = entity->next;
	}
	if (headEntity==nullptr) {
		tailEntity = nullptr;
	}
	delete entity;
}

Entity* EntitiesSystem::GetEntity(int index) {
	Entity* entity = headEntity;
	if (entity != nullptr) {
		if (index < entitiesCount) {
			for (size_t i = 0; i < index; i++) {
				entity = entity->next;
			}
			return entity;
		}
		else {
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
	return nullptr;
}