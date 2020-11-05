#pragma once

struct SDL_Window;
struct SDL_Renderer;

class RenderWindow
{
public:
	RenderWindow(int width, int height);
	~RenderWindow();

	void Run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};