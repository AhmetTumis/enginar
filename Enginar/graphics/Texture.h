#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../common/EnginarMath.h"
#include <vector>

class Texture
{
public:
	Texture(const char* _path);
	virtual void init();

	int defaultTextureWidth = 1;
	int defaultTextureHeight = 1;

	SDL_Rect textureRect; //Rendering
	SDL_Rect physicsRect; //Physics shape
	double rotation;

	SDL_Texture* getSDLTextures() { return sdlTexture; };
	SDL_Texture* sdlTexture;

	bool render = true;

protected:
	const char* path;
	bool initialized = false;

};

