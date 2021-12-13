#pragma once

#include "SDL.h"
#include <vector>
#include "Texture.h"

using namespace std;

class Window
{
public:
	Window();
	~Window();

	void initializeWindow(const char* title, int x, int y, bool isFullscreen = false);

	void addTexture(Texture* texture);
	void render();

	SDL_Window* getWindow() { return window; }
	SDL_Renderer* getRenderer() { return renderer; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	vector<Texture*> textures;
};

