#pragma once

#include "../graphics/Window.h"
#include "SDL_image.h"
#include "../common/GameObject.h"
#include "../io/InputManager.h"
#include "../physics/PhysicsMotor.h"
#include "../Scene.h"

class Game
{
public:
	Game();
	~Game();

	inline static Game* instance;
	inline static Game* getInstance()
	{
		return instance;
	}

	PhysicsMotor* physicsMotor;

	virtual void initializeGame(Window* _window);

	//gameloop
	void loop();

	//vector<GameObject*> getGameObjects() { return gameObjects; }

	Scene* getActiveScene() { return activeScene; }

	void addGameObject(GameObject* gameObject);
	InputManager* inputManager;

	Window* getWindow() { return window; }

private:
	Window* window;
	//vector<GameObject*> gameObjects;
	vector<Scene*> scenes;
	Scene* activeScene;
};