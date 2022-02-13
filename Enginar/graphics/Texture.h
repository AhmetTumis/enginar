#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../common/EnginarMath.h"
#include <vector>

class Texture
{
public:
	Texture(const char* _paths);
	void init();

	SDL_Rect textureRect;
	double rotation;

	SDL_Texture* getSDLTextures() { return sdlTexture; };
	SDL_Texture* sdlTexture;

	bool render = true;

private:
	const char* path;
	bool initialized = false;

};

