#pragma once

#include "SDL.h"
#include <vector>
#include "Texture.h"
#include <string>
#include "../common/Vector.h"

using namespace std;

class Window
{
public:
	Window();
	~Window();

	void initializeWindow(const char* title, int x, int y, bool isFullscreen = false);
	
	void destroy(); // yok et
	void resize(std::string title, unsigned int width, unsigned int height); 
	void minimize();
	void maximize();
	void restore();
	bool toggleFullScreen();
	void center();
	void move(int x, int y);
	
	void setTitle(std::string title);


	void addTexture(Texture* texture);
	void render();

	SDL_Window* getWindow() { return window; }
	SDL_Renderer* getRenderer() { return renderer; }

	vector2 getWindowSize();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	vector<Texture*> textures;
};

