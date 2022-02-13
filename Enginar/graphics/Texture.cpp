#include "Texture.h"
#include "TextureManager.h"

Texture::Texture(const char* _path)
{
	path = _path;
}

void Texture::init()
{
	SDL_Surface* textureSurface = IMG_Load(path);
	sdlTexture = (SDL_CreateTextureFromSurface(TextureManager::getInstance()->getWindow()->getRenderer(), textureSurface));
	SDL_FreeSurface(textureSurface);
	TextureManager::getInstance()->addTextureToWindow(this);

	initialized = true;
}