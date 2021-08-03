#include <iostream>
#include <INGEngine.h>

using namespace ING::Engine;
using namespace ING::Engine::EntityComponents;


#pragma region INGAppClass

class INGApp: public INGEngine {
public:
	INGApp() {

	}
	~INGApp() {

	}
	virtual void OnStart() override;
};



Mesh* mesh;

Shader* shader;

Material* material;

RenderState* renderState;

RasterizerState* rasterizerState;
DepthStencilState* depthStencilState;
BlendState* blendState;

Renderer* renderer;



void INGApp::OnStart() {

	mesh = resources->ImportMesh_DemoFile("skull.txt");

	shader = graphics->CreateShaderFromFile(L"demo.fx");
	shader->inputLayoutDesc = Vertex::inputLayoutDesc;
	shader->CreateInputLayout();

	material = graphics->materialManager->CreateMaterial(shader);

	renderState = graphics->CreateRenderState();

	rasterizerState = new RasterizerState();
	depthStencilState = new DepthStencilState();
	blendState = new BlendState();

	renderState->Set(rasterizerState,depthStencilState,blendState);
	
	renderer = graphics->renderSystem->CreateRenderer();

	renderer->SetMesh(mesh);

	renderer->SetMaterial(material);

	renderer->SetRenderState(renderState);

	DefaultStart();
}


#pragma endregion INGAppClass



#pragma region App

INGApp* app;

#pragma endregion App




#pragma region Program
int main() {

	app = new INGApp();


	app->window->name = L"ING Demo Project";
	app->window->clientWidth = 900;
	app->window->clientHeight = 600;



	if (!app->Init()) {
		return false;
	}


	if (!app->Run()) {
		return false;
	}



	return 0;
}
#pragma endregion Program