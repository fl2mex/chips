#include "Include.h"
#include "Window.h"
#include "Chip8.h"

int main(int argc, char *argv[])
{
	Window *window = new Window("App", 1280, 640, DEBUG_ON);
	Chip8* chip8 = new Chip8();

	while (window->Running())
	{
		chip8->Draw();

		window->HandleEvents();
		window->Update(chip8->pixels);
		window->Render();
	}

	delete chip8;
	delete window;
	return 0;
}