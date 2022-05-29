#include "Text.h"
#include "TextureManager.h"

void Text::init(const char* text, const char* fontPath, int fontSize, SDL_Rect _rect)
{
	font = TTF_OpenFont(fontPath, fontSize);
	color = { 255, 255, 255 };
	surface = TTF_RenderText_Solid(font, text, color);
	sdlTexture = SDL_CreateTextureFromSurface(TextureManager::getInstance()->getWindow()->getRenderer(), surface);

	textureRect = _rect;

	SDL_FreeSurface(surface);
	TextureManager::getInstance()->addTextureToWindow(this);

	defaultTextureWidth = surface->w;
	defaultTextureHeight = surface->h;

	initialized = true;
}

void Text::setText(const char* text)
{
	surface = TTF_RenderText_Solid(font, text, color);
	sdlTexture = SDL_CreateTextureFromSurface(TextureManager::getInstance()->getWindow()->getRenderer(), surface);
}
