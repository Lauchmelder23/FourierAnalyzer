#include "Screen.hpp"
#include <stdexcept>
#include <SDL.h>

Screen::Screen(SDL_Renderer* renderer, int x, int y, int w, int h) :
	screenSpace{ x, y, w, h }
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
	if (texture == nullptr)
	{
		throw std::runtime_error(SDL_GetErrorMsg((char*)malloc(512), 511));
	}
}

Screen::~Screen()
{
	SDL_DestroyTexture(texture);
}