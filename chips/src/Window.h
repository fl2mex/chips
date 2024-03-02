#pragma once
#include "Include.h"

class Window
{
public:
	Window(std::string title, uint32_t w, uint32_t h, bool debug);
	~Window();

	bool running() { return isRunning; }

	void HandleEvents();
	void Update(uint32_t pixels[64*32]);
	void Render();

private:
	bool isRunning = false;
	bool isDebug = false;

	SDL_Window* m_Window{ nullptr };
	SDL_Renderer* m_Renderer{ nullptr };
	SDL_Texture* m_Framebuffer{ nullptr };
};