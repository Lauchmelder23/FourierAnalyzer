#include <iostream>
#include <SDL.h>

int main(int argc, char** argv)
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	if (SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_SHOWN, &window, &renderer))
	{
		std::cerr << "Failed to initialize Window and Renderer" << std::endl;
		return -1;
	}

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

		SDL_SetRenderDrawColor(renderer, 20, 40, 210, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}