#pragma once

#include "SDL.h"
#include <vector>

using namespace std;

class Window
{
public:
	Window();
	~Window();

	void initializeWindow(const char* title, int x, int y, int width, int height, bool isFullscreen = false);

	void addTexture(SDL_Texture* texture);
	void render();

	SDL_Window* getWindow() { return window; }
	SDL_Renderer* getRenderer() { return renderer; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	vector<SDL_Texture*> textures;
};

