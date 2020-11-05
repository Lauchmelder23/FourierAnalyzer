#pragma once

#include "../Screen.hpp"

class DummyScreen : public Screen
{
public:
	DummyScreen(SDL_Renderer* renderer, int x, int y, int w, int h);
	
	void Update();
	void Render(SDL_Renderer* renderer);
};