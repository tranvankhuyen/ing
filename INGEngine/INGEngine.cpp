// INGEngine.cpp : Defines the functions for the static library.
//











#include "pch.h"
#include "framework.h"
#include <iostream>




#include "INGEngine.h"

using namespace ING::Engine;


INGEngine::INGEngine() {
	graphics = new Graphics(this);
	entitiesSystem = new EntitiesSystem(this);
	window = new Window(this);
	physics = new Physics(this);
	time = new Time(this);
	math = new Math(this);
	resources = new Resources(this);
}

INGEngine::~INGEngine() {

}


bool INGEngine::Init() {
	
	if (!window->Init()) {
		return false;
	}

	if (!graphics->Init()) {
		return false;
	}

	OnSetup();

	return true;
}


bool INGEngine::Run() {
	OnStart();
	return true;
}




#pragma region Events

void INGEngine::OnFixedUpdate() {
	DefaultFixedUpdate();
}

void INGEngine::OnSetup() {
	DefaultSetup();
}

void INGEngine::OnStart() {
	DefaultStart();
}

void INGEngine::OnPreUpdate() {
	DefaultPreUpdate();
}

void INGEngine::OnUpdate() {
	DefaultUpdate();
}

void INGEngine::OnLateUpdate() {
	DefaultLateUpdate();
}

void INGEngine::OnPreRender() {
	DefaultPreRender();
}

void INGEngine::OnRender() {
	DefaultRender();
}

void INGEngine::OnAfterRender() {
	DefaultAfterRender();
}

#pragma endregion Events




#pragma region DefaultEvents

void INGEngine::DefaultFixedUpdate() {
	entitiesSystem->OnFixedUpdate();
}

void INGEngine::DefaultSetup() {
	entitiesSystem->OnSetup();
}

void INGEngine::DefaultStart() {
	entitiesSystem->OnStart();


	while (window->isRunning) {
		window->Boardcast();

		OnPreUpdate();
		OnUpdate();
		OnLateUpdate();
		OnPreRender();
		OnRender();
		OnAfterRender();

	}

}

void INGEngine::DefaultPreUpdate() {
	entitiesSystem->OnPreUpdate();
}

void INGEngine::DefaultUpdate() {
	entitiesSystem->OnUpdate();
}

void INGEngine::DefaultLateUpdate() {
	entitiesSystem->OnLateUpdate();
}

void INGEngine::DefaultPreRender() {
	entitiesSystem->OnPreRender();
}

void INGEngine::DefaultRender() {

	float color[4] = {0,0,0,1};

	graphics->deviceContext->ClearRenderTargetView(color);

	entitiesSystem->OnRender();

	graphics->swapChain->Present();

}

void INGEngine::DefaultAfterRender() {
	entitiesSystem->OnAfterRender();
}


#pragma endregion Events





// TODO: This is an example of a library function
void fnINGEngine()
{

}



