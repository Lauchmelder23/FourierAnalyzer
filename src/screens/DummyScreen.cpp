#include "screens/DummyScreen.hpp"
#include <SDL.h>

DummyScreen::DummyScreen(SDL_Renderer* renderer, int x, int y, int w, int h) :
	Screen(renderer, x, y, w, h)
{
}

void DummyScreen::Update()
{
	// Do nothing
}

void DummyScreen::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, screenSpace);
}