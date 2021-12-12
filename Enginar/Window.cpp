#include "Window.h"

Window::Window()
{
}

Window::~Window()
{
}

void Window::initializeWindow(const char* title, int x, int y, int width, int height, bool isFullScreen)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Enginar", x, y, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_SetWindowFullscreen(window, isFullScreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void Window::addTexture(SDL_Texture* texture)
{
	textures.push_back(texture);
}

void Window::render()
{
	SDL_RenderClear(renderer);

	for (int i = 0; i < textures.size(); i++)
	{
		SDL_RenderCopy(renderer, textures[i], NULL, NULL);
	}

	SDL_RenderPresent(renderer);
}
