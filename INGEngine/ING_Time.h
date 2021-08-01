#ifndef TIME_H
#define TIME_H

#include "INGEngine.h"


namespace ING {
	namespace Engine {

		class INGEngine;

		class Time {

		public:
			Time(INGEngine* INGEngine);
			~Time();

		public:
			INGEngine* INGEngine;

		};

	}
}

#endif