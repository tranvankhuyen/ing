#include "pch.h"
#include "Shader.h"

using namespace ING::Engine;


Shader::Shader() {

}

Shader::~Shader() {

}



void Shader::CreateInputLayout() {
	
	


	graphics->d3dDevice->CreateInputLayout(inputLayoutDesc.layout, inputLayoutDesc.elementsCount, pvsblob->GetBufferPointer(), pvsblob->GetBufferSize(), &inputLayout);
}