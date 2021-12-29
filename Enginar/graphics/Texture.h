#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "EnginarMath.h"
#include <vector>

class Texture
{
public:
	Texture(const char* _paths[]);
	void init();

	SDL_Rect textureRect;
	double rotation;

	SDL_Texture* getSDLTextures() { return *sdlTextures; };
	SDL_Texture* sdlTextures[100];

private:
	const char* paths[100];
	bool initialized = false;

};

