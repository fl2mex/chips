#include "Include.h"
#include "Window.h"

int main(int argc, char *argv[])
{
	Window *window = new Window("App", 1280, 640, DEBUG_ON);

	uint32_t pixels[64 * 32]{ 0 };
	for (uint32_t i = 0; i < 64 * 32; i += 1)
	{
		pixels[i] = SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), i*255/2048, i*255/2048, i*255/2048, 255);
	}

	while (window->running())
	{
		window->HandleEvents();
		window->Update(pixels);
		window->Render();
	}

	delete window;

	return 0;
}