#include "Game.h"
#include "Texture.h"
#include "GameObject.h"

Game::Game()
{
}

Game::~Game()
{
}
Texture* myTexture = nullptr;
void Game::initializeGame(Window* _window)
{
	//Window'u eşitle
	window = _window;

	GameObject* go = new GameObject();
	go->init();
	myTexture = new Texture("assets/k.png");
	go->AddComponent(make_any<Texture*>(myTexture));
	myTexture->setScale(300);

	loop();
}

//Gameloop
void Game::loop()
{
	int i = 0;
	while (true)
	{
		i++;
		if (i % 15 == 0)
		{
			//myTexture->setPositionX();
		}
		window->render();
	}
}
