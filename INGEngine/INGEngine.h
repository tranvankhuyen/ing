#ifndef INGEngine_H
#define INGEngine_H

#include "Graphics.h"
#include "EntitiesSystem.h"
#include "ING_Window.h"
#include "Physics.h"
#include "ING_Time.h"
#include "ING_Math.h"
#include "Resources.h"


namespace ING {
	namespace Engine {

		class Graphics;

		class EntitiesSystem;

		class Window;

		class Physics;

		class Time;

		class Math;

		class Resources;

		class INGEngine {

		public:
			INGEngine();
			~INGEngine();

		public:
			Graphics* graphics;
			Window* window;
			EntitiesSystem* entitiesSystem;
			Physics* physics;
			Time* time;
			Math* math;
			Resources* resources;

		public:
			bool Init();
			bool Run();

		public:
			virtual void OnFixedUpdate();
			void DefaultFixedUpdate();

			virtual void OnSetup();
			void DefaultSetup();

			virtual void OnStart();
			void DefaultStart();

			virtual void OnPreUpdate();
			void DefaultPreUpdate();

			virtual void OnUpdate();
			void DefaultUpdate();

			virtual void OnLateUpdate();
			void DefaultLateUpdate();

			virtual void OnPreRender();
			void DefaultPreRender();

			virtual void OnRender();
			void DefaultRender();

			virtual void OnAfterRender();
			void DefaultAfterRender();


		};
	}
}


#endif