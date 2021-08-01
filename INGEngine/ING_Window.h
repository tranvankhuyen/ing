#ifndef WINDOW_H
#define WINDOW_H

#include "INGEngine.h"

#include <Windows.h>
#include <windowsx.h>



namespace ING {
	namespace Engine {

		class INGEngine;

		class Window {

		public:
			Window(INGEngine* INGEngine);
			~Window();

		public:
			INGEngine* INGEngine;

		public:
			UINT clientWidth;
			UINT clientHeight;
			LPCWSTR name;
			HWND hwnd;
			bool isRunning;

		

		public:
			bool ThisCreateWindow();

		public:
			void OnCreate();
			void OnUpdate();
			void OnDestroy();
			void OnResize();

		public:
			void Boardcast();

		public:
			bool Init();

		};

	}
}

#endif