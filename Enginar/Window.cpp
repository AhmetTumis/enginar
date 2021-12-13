#include "Window.h"
#include "Constants.h"
#include "TextureManager.h"

Window::Window()
{
}

Window::~Window()
{
}

void Window::initializeWindow(const char* title, int x, int y, bool isFullScreen)
{
	//Init kýsmý
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Enginar", x, y, WindowConstants::windowWidth, WindowConstants::windowHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	//Arkaplan rengi
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	//Fullscreen olup olmamasý
	SDL_SetWindowFullscreen(window, isFullScreen ? SDL_WINDOW_FULLSCREEN : 0);

}

//Texture listesine texture ekle
void Window::addTexture(Texture* texture)
{
	textures.push_back(texture);
}

void Window::render()
{
	//Önceki frame'i temizle
	SDL_RenderClear(renderer);

	//Yeni frame'de texture'larý render'la
	for (int i = 0; i < textures.size(); i++)
	{
		auto tex = textures[i];
		SDL_RenderCopy(renderer, tex->getSDLTexture(), NULL, &tex->rect1);
	}

	//Renderer'ý ekranda göster
	SDL_RenderPresent(renderer);
}
