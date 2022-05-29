#pragma once

#include "Texture.h"
#include "SDL_ttf.h"

class Text : public Texture
{
public:
	Text(const char* _path) : Texture(_path) {}

	void init(const char* text, const char* fontPath, int fontSize, SDL_Rect _rect);

	void setText(const char* text);

private:
	TTF_Font* font;
	SDL_Color color;
	SDL_Surface* surface;
};

