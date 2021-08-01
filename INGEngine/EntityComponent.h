#ifndef ENTITYCOMPONENT_H
#define ENTITYCOMPONENT_H

#include <iostream>


namespace ING {
	namespace Engine {

		namespace EntityComponents {

		}

		class INGEngine;

		class Entity;

		class EntityComponent
		{
		public:
			EntityComponent();
			~EntityComponent();

		public:
			Entity* entity;

		public:
			virtual void OnFixedUpdate();

			virtual void OnSetup();

			virtual void OnStart();

			virtual void OnPreUpdate();

			virtual void OnUpdate();

			virtual void OnLateUpdate();

			virtual void OnPreRender();

			virtual void OnRender();

			virtual void OnAfterRender();

			virtual void OnComponentAdded();


		};
	}
}


#endif