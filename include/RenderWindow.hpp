#pragma once

#include <vector>

struct SDL_Window;
struct SDL_Renderer;
class Screen;

class RenderWindow
{
public:
	RenderWindow(int width, int height);
	~RenderWindow();

	void AddScreen(Screen* screen);
	void RemoveScreen(Screen* screen);

	void Run();

public:
	SDL_Window* window;
	SDL_Renderer* renderer;

private:
	std::vector<Screen*> screens;
};