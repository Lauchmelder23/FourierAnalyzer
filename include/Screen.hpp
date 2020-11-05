#pragma once

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class Screen
{
public:
	Screen(SDL_Renderer* renderer, int x, int y, int w, int h);
	~Screen();

	virtual void Update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;

protected:
	SDL_Rect* screenSpace;
	SDL_Texture* texture;
};