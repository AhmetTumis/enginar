#include "Game.h"
#include "Texture.h"
#include "GameObject.h"

Game::Game()
{
}

Game::~Game()
{
}
GameObject* go = nullptr;
void Game::initializeGame(Window* _window)
{
	//Window'u eþitle
	window = _window;

	go = new GameObject();
	go->init();
	const char* paths[2];

	paths[0] = "assets/k.png";
	paths[1] = "assets/char.png";

	Texture* myTexture = new Texture(paths);

	go->addComponent(make_any<Texture*>(myTexture));
	go->getTransform()->setScale(300);
	myTexture->textureRect.w = myTexture->textureRect.h = 300;
	gameObjects.push_back(go);
	
	loop();
}

SDL_Event event;

//Gameloop
void Game::loop()
{
	int i = 0;
	while (true)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					go->getTransform()->setPositionX();
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
				}
				break;
			}
		}

		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->update();
		}

		window->render();
	}
}
