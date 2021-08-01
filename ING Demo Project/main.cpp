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

void INGApp::OnStart() {

	Mesh* mesh = resources->ImportMesh_DemoFile("skull.txt");

	Shader* shader = graphics->CreateShaderFromFile(L"demo.fx");

	Material* material = graphics->materialManager->CreateMaterial(shader);

	RenderState* renderState = graphics->CreateRenderState();

	RasterizerState* rasterizerState = new RasterizerState();
	DepthStencilState* depthStencilState = new DepthStencilState();
	BlendState* blendState = new BlendState();

	renderState->Set(rasterizerState,depthStencilState,blendState);
	
	Renderer* renderer = graphics->renderSystem->CreateRenderer();

	renderer->mesh = mesh;

	renderer->material = material;

	renderer->renderState = renderState;

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