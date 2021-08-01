#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>

namespace ING {
	namespace Engine {

		class EntitiesSystem;

		class EntityComponent;

		class Entity
		{
		public:
			Entity();
			~Entity();
		
		public:
			EntitiesSystem* system;

		public:
			std::string name;
			std::string tag;
			bool isActive;

		public:
			std::vector<EntityComponent*> components;
			Entity* next;
			Entity* prev;



		public:
			template<class T> T* AddComponent() {
				T* component = new T();
				component->entity = this;
				size_t size = this->components.size();

				this->components.resize(size+1);
				this->components[size] = static_cast<EntityComponent*>(component);

				return component;
			}
			template <class DstType, class SrcType> bool IsType(const SrcType* src){
				return dynamic_cast<const DstType*>(src) != nullptr;
			}
			template<class T> T* GetComponent() {

				for (size_t i = 0; i < this->components.size();i++) {
					if (IsType<T,EntityComponent>(components[i])) {
						return dynamic_cast<T*>(components[i]);
					}
				}

				return nullptr;
			}


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