#ifndef SHADERCOMPILER_H
#define SHADERCOMPILER_H

#include "INGEngine.h"
#include <iostream>

namespace ING {
	namespace Engine {


		class Graphics;

		class ShaderCompiler {
		public:
			ShaderCompiler(Graphics* graphics);
			~ShaderCompiler();

		public:
			Graphics* graphics;

		public:
			bool Init();

		public:
			std::string Compile(std::string source);

		};

	}
}

#endif 