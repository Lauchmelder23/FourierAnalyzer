#include "Screen.hpp"
#include <stdexcept>
#include <SDL.h>

Screen::Screen(SDL_Renderer* renderer, int x, int y, int w, int h) :
	screenSpace(new SDL_Rect{ x, y, w, h })
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
	if (texture == nullptr)
	{
		throw std::runtime_error(SDL_GetErrorMsg((char*)malloc(512), 511));
	}
}

Screen::~Screen()
{
	delete screenSpace;
	screenSpace = nullptr;

	SDL_DestroyTexture(texture);
}