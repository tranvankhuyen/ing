#ifndef PHYSICS_H
#define PHYSICS_H

#include "INGEngine.h"

namespace ING{
	namespace Engine {
		
		class INGEngine;

		class Physics {

		public:
			Physics(INGEngine* INGEngine);
			~Physics();

		public:
			INGEngine* INGEngine;

		};


	}
}


#endif