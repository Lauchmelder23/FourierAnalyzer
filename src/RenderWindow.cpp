#include "RenderWindow.hpp"
#include <SDL.h>
#include <stdexcept>

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

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}
}