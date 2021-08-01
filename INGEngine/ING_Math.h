#ifndef MATH_H
#define MATH_H

#include "INGEngine.h"
#include <d3d11.h>
#include <DirectXMath.h>



namespace ING {
	namespace Engine {

		class Math
		{
		public:
			Math(INGEngine* INGEngine);
			~Math();

		public:
			INGEngine* INGEngine;

		};

	}
}

#endif