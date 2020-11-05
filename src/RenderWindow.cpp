#include "RenderWindow.hpp"
#include <stdexcept>
#include <SDL.h>
#include "Screen.hpp"

RenderWindow::RenderWindow(int width, int height)
{
	if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer))
	{
		throw std::runtime_error(SDL_GetErrorMsg((char*)malloc(512), 511));
	}
}

RenderWindow::~RenderWindow()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderWindow::AddScreen(Screen* screen)
{
	screens.push_back(screen);
}

void RenderWindow::RemoveScreen(Screen* screen)
{
	for (std::vector<Screen*>::iterator it = screens.begin(); it != screens.end();)
	{
		if (*it == screen)
			it = screens.erase(it);
		else
			it++;
	}
}

void RenderWindow::Run()
{
	SDL_Event event;
	bool isOpen = true;

	while (isOpen)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_WINDOWEVENT)
			{
				switch (event.window.event)
				{
				case SDL_WINDOWEVENT_CLOSE: isOpen = false; break;
				}
			}
		}

		for (Screen* screen : screens)
			screen->Update();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		for (Screen* screen : screens)
			screen->Render(renderer);

		SDL_RenderPresent(renderer);
	}
}