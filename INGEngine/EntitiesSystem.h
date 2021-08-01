#ifndef ENTITIESSYSTEM_H
#define ENTITIESSYSTEM_H

#include "INGEngine.h"

#include "INGEntityComponents.h"

#include "EntityComponent.h"

#include "EntityGroup.h"

#include <iostream>
#include <vector>

namespace ING {
	namespace Engine {

		class INGEngine;

		class Entity;

		class EntitiesSystem
		{
		public:
			EntitiesSystem(INGEngine* INGEngine);
			~EntitiesSystem();

		public:
			INGEngine* INGEngine;

		public:
			Entity* headEntity;
			Entity* tailEntity;
			int entitiesCount;



		public:
			void AddEntity(Entity* entity);
			Entity* CreateEntity();
			Entity* GetEntity(int index);
			void RemoveEntity(Entity* entity);

		public:
			void OnFixedUpdate();

			void OnSetup();

			void OnStart();

			void OnPreUpdate();

			void OnUpdate();

			void OnLateUpdate();

			void OnPreRender();

			void OnRender();

			void OnAfterRender();

		};
	}
}


#endif