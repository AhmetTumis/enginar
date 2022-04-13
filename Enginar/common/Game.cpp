#include "Game.h"
#include "../graphics/Texture.h"
#include "GameObject.h"
#include "../io/InputManager.h"
#include "../graphics/Sprite.h"
#include "../physics/Collision.h"
#include "../common/Vector.h"
#include "../physics/RigidBody.h"
#include "../sound/Sound.h"

Game::Game()
{
}

Game::~Game()
{
}
GameObject* go = nullptr;
GameObject* go2 = nullptr;
InputManager inputManager;

Sound* Asound;



void Game::initializeGame(Window* _window)
{
	//Window'u e�itle
	window = _window;
	
	Asound = new Sound("./assets/sounds/collide.wav");
	Asound->SetupDevice();
	

#pragma region TEST_GAME
	go = new GameObject();
	go->init();



	Sprite* playerAdventurer = new Sprite();

	vector<const char*> idleSprites = {
		"assets/adventurer-idle-2-00.png",
		"assets/adventurer-idle-2-01.png",
		"assets/adventurer-idle-2-02.png",
		"assets/adventurer-idle-2-03.png",
	};

	

	Layer* layerIDLE = playerAdventurer->createLayer("IDLE", idleSprites);

	//playerAdventurer->add(layerIDLE, "assets/adventurer-idle-2-XX.png");
	playerAdventurer->setCurrentLayer("IDLE");

	go->addComponent(make_any<Sprite*>(playerAdventurer));
	go->getTransform()->setScale(300);

	auto rect = (any_cast<Transform*>(go->getComponent(typeid(Transform*))))->rect1;

	CircleCollider* col = new CircleCollider("", 15);

	go->addComponent(make_any<Collider*>(dynamic_cast<Collider*>(col)));

	RigidBody* rb = new RigidBody(1, 1.0f);

	go->addComponent(make_any<RigidBody*>(dynamic_cast<RigidBody*>(rb)));

	gameObjects.push_back(go);

	go2 = new GameObject();
	go2->init();

	auto tex = new Texture("assets/char.png");

	go2->addComponent(make_any<Texture*>(tex));

	go2->getTransform()->setScale(300);
	go2->getTransform()->setPositionX(300);

	auto rect2 = (any_cast<Transform*>(go2->getComponent(typeid(Transform*))))->rect1;

	CircleCollider* col2 = new CircleCollider("", 15);

	go2->addComponent(make_any<Collider*>(dynamic_cast<Collider*>(col2)));

	gameObjects.push_back(go2);
#pragma endregion

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
			//printf("%f\n", 1000.0f / (deltaTime + .1f));

#pragma region Input
			if (inputManager.isDown(SDLK_RIGHT) || inputManager.isDown("d"))
			{	
				//Asound->PlaySound();
				go->getTransform()->setPositionX(go->getTransform()->getPositionX() + 1);
			}
			if (inputManager.isDown(SDLK_LEFT) || inputManager.isDown("a"))
			{
				//Asound->PlaySound();
				go->getTransform()->setPositionX(go->getTransform()->getPositionX() - 1);
			}
			if (inputManager.isDown(SDLK_UP) || inputManager.isDown("w"))
			{
				//Asound->PlaySound();

				/*auto pos = *go->getTransform()->getPosition();
				auto dir = *go->getTransform()->getForward();
				go->getTransform()->setPosition(pos + dir);*/

				go->getTransform()->setPositionY(go->getTransform()->getPositionY() - 1);
			}
			if (inputManager.isDown(SDLK_DOWN) || inputManager.isDown("s"))
			{
				//Asound->PlaySound();

				go->getTransform()->setPositionY(go->getTransform()->getPositionY() + 1);
			}
			if (inputManager.isDown(SDLK_KP_PLUS))
			{
				auto s1 = *go->getTransform()->getScale();
				auto t = s1 + vector2(1,1);
				auto xx = t.data[0][0];
				auto yy = t.data[0][1];
				go->getTransform()->setScale(&t);
			}
			// if (inputManager.isDown(SDLK_KP_MINUS))
			// {
			// 	auto rb = go->rigidbodyComponent;
			// 	rb->applyForce(VEC2_UP*3);
			// }
			if (inputManager.isDown(SDLK_q))
			{
				go->getTransform()->setRotation(go->getTransform()->getRotation() - 1);
			}
			if (inputManager.isDown(SDLK_e))
			{
				go->getTransform()->setRotation(go->getTransform()->getRotation() + 1);
			}

			inputManager.ListenEvent(event);
#pragma endregion

			for (int i = 0; i < gameObjects.size(); i++)
			{
				gameObjects[i]->update();
			}

			window->render();

			auto col1 = dynamic_cast<CircleCollider*>(any_cast<Collider*>(go->getComponent(typeid(Collider*))));
			auto col2 = dynamic_cast<CircleCollider*>(any_cast<Collider*>(go2->getComponent(typeid(Collider*))));

			if (Collision::isCollidingCircleAndCircle(*col1,*col2))
			{
				printf("çarpışış");
			}
		}

	}
}
