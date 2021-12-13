#include "Texture.h"
#include "TextureManager.h"

Texture::Texture(const char* _path)
{
	path = _path;
}

void Texture::init()
{
	SDL_Surface* textureSurface = IMG_Load(path);
	sdlTexture = SDL_CreateTextureFromSurface(TextureManager::getInstance()->getWindow()->getRenderer(), textureSurface);
	SDL_FreeSurface(textureSurface);
	TextureManager::getInstance()->addTextureToWindow(this);
	initialized = true;
}

void Texture::setScale(int scale)
{
	rect1.w = scale;
	rect1.h = scale;
}

void Texture::setScale(vector2& newScale)
{
	rect1.w = newScale.x;
	rect1.h = newScale.y;
}

void Texture::setScaleX(int x)
{
	rect1.w = x;
}

void Texture::setScaleY(int y)
{
	rect1.h = y;
}