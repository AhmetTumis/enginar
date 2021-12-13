#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "EnginarMath.h"

class Texture
{
public:
	Texture(const char* path);
	void init();
	void setScale(int size);
	void setScale(vector2& newScale);
	void setScaleX(int x);
	void setScaleY(int y);
	SDL_Rect rect1;

	SDL_Texture* getSDLTexture() { return sdlTexture; };

private:
	SDL_Texture* sdlTexture;
	const char* path = "";
	bool initialized = false;

};

