#include "pch.h"
#include "ING_Window.h"

using namespace ING::Engine;


static Window* window;


Window::Window(ING::Engine::INGEngine* INGEngine) {
	this->INGEngine = INGEngine;
	window = this;
}


Window::~Window() {

}





LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{

	switch (msg)
	{
	case WM_CREATE:
	{

		break;
	}

	case WM_DESTROY:
	{
		window->OnDestroy();
		window->isRunning = false;
		::PostQuitMessage(0);
		break;
	}


	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}


bool Window::ThisCreateWindow() {
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"INGWindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	if (!::RegisterClassEx(&wc))
		return false;

	this->hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"INGWindowClass", this->name,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, this->clientWidth, this->clientHeight,
		NULL, NULL, NULL, this);

	if (!this->hwnd)
		return false;


	::ShowWindow(this->hwnd, SW_SHOW);
	::UpdateWindow(this->hwnd);

	this->isRunning = true;
	return true;
}


bool Window::Init() {

	if (!(this->ThisCreateWindow())) {
		return false;
	}

	return true;
}



void Window::OnCreate() {

}

void Window::OnUpdate() {

}


void  Window::OnDestroy() {
	this->isRunning = false;
}

void Window::OnResize() {

}

void Window::Boardcast() {
	MSG msg;

	this->OnUpdate();

	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Sleep(1);
}