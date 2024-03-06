#include "Include.h"
#include "Window.h"

int main(int argc, char *argv[])
{
	Window *window = new Window("App", 1280, 640, DEBUG_ON);

	uint8_t pixels[64 * 32]{ 0 };

	uint8_t black = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGB332), 0, 0, 0);
	uint8_t white = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGB332), 255, 255, 255);
	
	for (uint16_t i = 0; i < 64 * 32; ++i)
	{
		pixels[i] = (i/64) % 2 ? (i % 2 ? black : white) : (i % 2 ? white : black);
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