#include "pch.h"
#include "ShaderCompiler.h"

using namespace ING::Engine;


ShaderCompiler::ShaderCompiler(Graphics* graphics) {
	this->graphics = graphics;
}

ShaderCompiler::~ShaderCompiler() {

}


bool ShaderCompiler::Init() {
	return true;
}

std::string ShaderCompiler::Compile(std::string source) {
	std::string result="";
	return result;
}