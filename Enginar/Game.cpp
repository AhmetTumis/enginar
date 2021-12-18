#include "Game.h"
#include "Texture.h"
#include "GameObject.h"
#include "InputManager.h"

Game::Game()
{
}

Game::~Game()
{
}
GameObject* go = nullptr;
InputManager inputManager;
void Game::initializeGame(Window* _window)
{
	//Window'u eþitle
	window = _window;

	go = new GameObject();
	go->init();
	const char* paths[2];

	paths[0] = "assets/squareheadchineseguy.png";
	paths[1] = "assets/char.png";

	Texture* myTexture = new Texture(paths);

	go->addComponent(make_any<Texture*>(myTexture));
	go->getTransform()->setScale(300);
	gameObjects.push_back(go);

	inputManager;
	
	loop();
}

SDL_Event event;

//Gameloop
void Game::loop()
{
	int i = 0;
	Uint32 a = 0, b = 0;
	while (true)
	{
		a = SDL_GetTicks();
		Uint32 deltaTime = a - b;

		if (deltaTime >= 1000/60.0)
		{
			b = a;
			printf("%f\n", 1000.0f / (deltaTime + .1f));

#pragma region Input
			if (inputManager.getKeyState(SDLK_RIGHT))
			{
				go->getTransform()->setPositionX(go->getTransform()->getPositionX() + 1);
			}
			if (inputManager.getKeyState(SDLK_LEFT))
			{
				go->getTransform()->setPositionX(go->getTransform()->getPositionX() - 1);
			}
			if (inputManager.getKeyState(SDLK_UP))
			{
				auto pos = *go->getTransform()->getPosition();
				auto dir = *go->getTransform()->getUp();
				go->getTransform()->setPosition(pos + dir);
				printf("%f", go->getTransform()->getForward()->getAngle(*go->getTransform()->getUp()));
			}
			if (inputManager.getKeyState(SDLK_DOWN))
			{
				go->getTransform()->setPositionY(go->getTransform()->getPositionY() + 1);
			}
			if (inputManager.getKeyState(SDLK_KP_PLUS))
			{
				go->getTransform()->setScale(*go->getTransform()->getScale() * 1.01f);
			}
			if (inputManager.getKeyState(SDLK_KP_MINUS))
			{
				go->getTransform()->setScale(*go->getTransform()->getScale() / 1.0025f);
			}
			if (inputManager.getKeyState(SDLK_q))
			{
				go->getTransform()->setRotation(go->getTransform()->getRotation() - 1);
			}
			if (inputManager.getKeyState(SDLK_e))
			{
				go->getTransform()->setRotation(go->getTransform()->getRotation() + 1);
			}

			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_KEYDOWN:
					inputManager.pressKey(event.key.keysym.sym);
					break;
				case SDL_KEYUP:
					inputManager.releaseKey(event.key.keysym.sym);
					break;
				}
			}
#pragma endregion

			for (int i = 0; i < gameObjects.size(); i++)
			{
				gameObjects[i]->update();
			}

			window->render();
		}
		
	}
}
