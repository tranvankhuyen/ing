#ifndef INGAPP_H
#define INGAPP_H

#include "INGAppEvent.h"


namespace ING {
	namespace Engine {

		class INGEngine;

		class INGApp {
		public:
			INGApp();
			~INGApp();

		public:
			INGEngine* INGEngine;
		};
	}
}

#endif