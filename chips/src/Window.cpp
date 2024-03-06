#include "Window.h"

Window::Window(std::string title, uint32_t w, uint32_t h, bool debug)
	: isDebug(debug)
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) throw std::exception("nuh uh");
	log("Window: SDL Initialised");
	
	m_Window = SDL_CreateWindow("App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (!m_Window) throw std::exception("nuh uh");
	log("Window: Window Created");
	
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_Renderer) throw std::exception("nuh uh");
	log("Window: Renderer Created");

	m_Framebuffer = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGB332, SDL_TEXTUREACCESS_TARGET, 64, 32);
	if (!m_Framebuffer) throw std::exception("nuh uh");
	log("Window: Framebuffer Created");

	isRunning = true;
}

Window::~Window()
{
	SDL_DestroyTexture(m_Framebuffer);
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
	log("Goodbye!");
}

void Window::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) // Yoda is genuinely smart
	{
		isRunning = false;
	}
}

void Window::Update(uint8_t pixels[64*32])
{
	SDL_UpdateTexture(m_Framebuffer, nullptr, pixels, 64*sizeof(uint8_t));
}

void Window::Render()
{
	SDL_RenderClear(m_Renderer);
	SDL_RenderCopy(m_Renderer, m_Framebuffer, nullptr, nullptr);
	SDL_RenderPresent(m_Renderer);
}