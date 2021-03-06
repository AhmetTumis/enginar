#include "Window.h"
#include "../common/Constants.h"
#include "../common/Game.h"
#include "TextureManager.h"
#include "../sound/Sound.h"
#include "SDL_ttf.h"

Window::Window()
{
}

Window::~Window()
{
}


void Window::initializeWindow(const char* title, int x, int y, bool isFullScreen)
{
	//Init k�sm�
	SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Init(SDL_INIT_AUDIO);
	window = SDL_CreateWindow("Enginar", x, y, 500, 900, SDL_WINDOW_SHOWN);
	
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (TTF_Init() < 0)
	{
		printf("mal amk");
	}

	//caption
	//SDL_WM_SetCaption(title, "radish.bmp");

	//Arkaplan rengi
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	//Fullscreen olup olmamas�
	SDL_SetWindowFullscreen(window, isFullScreen ? SDL_WINDOW_FULLSCREEN : 0);

}

//Texture listesine texture ekle
void Window::addTexture(Texture* texture)
{
	textures.push_back(texture);
}
int k = 0, t = 0;

void Window::render()
{
	t++;
	//�nceki frame'i temizle
	SDL_RenderClear(renderer);
	//Yeni frame'de texture'lar� render'la
	for (int i = 0; i < textures.size(); i++)
	{
		auto tex = textures[i];
		if (!tex->render)
			continue;

		SDL_RenderCopyEx(renderer, tex->sdlTexture, NULL, &tex->textureRect, tex->rotation, NULL, SDL_FLIP_NONE);
	}

	//SDL_FreeSurface(surfaceMessage);
	//SDL_DestroyTexture(Message);

	//Renderer'� ekranda g�ster
	SDL_RenderPresent(renderer);
}

vector2 Window::getWindowSize()
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	return vector2(w, h);
}


void Window::minimize(){
	SDL_MinimizeWindow(this->window);
}
void Window::maximize(){
	SDL_MaximizeWindow(this->window);
}

void Window::restore(){
	SDL_RestoreWindow(this->window);	
}
void Window::destroy(){
	if(this->window){
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
	if(this->renderer){
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}
}

void Window::resize(std::string, unsigned int width, unsigned int height){
	this->destroy();

	SDL_CreateWindowAndRenderer(0,0,SDL_WINDOW_FULLSCREEN_DESKTOP, &(this->window), &(this->renderer));

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(this->renderer, width, height);

	//this->setTitle(title);

	//this->surface  = SDL_GetWindowSurface(this->window);
    //if (!(this->surface))
	  //  return;

    //this->width  = width;
    //this->height = height;
	//*s/
}

bool Window::toggleFullScreen(){

	return true;
}

void Window::setTitle(std::string title)
{
	if (this->window)
		SDL_SetWindowTitle(this->window, title.c_str());
}