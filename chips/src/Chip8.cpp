#include "Chip8.h"

Chip8::Chip8()
{
	isDebug = true;
}

Chip8::~Chip8()
{
	log("Goodbye, Chip-8!");
}

void Chip8::Draw()
{
	uint8_t black = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGB332), 0, 0, 0);
	uint8_t white = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGB332), 255, 255, 255);

	for (uint16_t i = 0; i < 64 * 32; ++i)
	{
		pixels[i] = (i / 64) % 2 ? (i % 2 ? black : white) : (i % 2 ? white : black);
	}
}

void Chip8::HandleInstruction()
{
}
