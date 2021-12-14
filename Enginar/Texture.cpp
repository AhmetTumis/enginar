#include "Texture.h"
#include "TextureManager.h"

Texture::Texture(const char* _paths[])
{
	for (int i=0; i < 2; i++)
	{
		paths[i] = _paths[i];
	}
}

void Texture::init()
{
	for (int i = 0; i < 2; i++)
	{
		SDL_Surface* textureSurface = IMG_Load(paths[i]);
		sdlTextures[i] = (SDL_CreateTextureFromSurface(TextureManager::getInstance()->getWindow()->getRenderer(), textureSurface));
		SDL_FreeSurface(textureSurface);
		TextureManager::getInstance()->addTextureToWindow(this);
	}


	initialized = true;
}