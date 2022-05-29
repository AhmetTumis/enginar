#pragma once
#include "GameObject.h"

class GameObject;

class Scene
{
public:
	bool isActiveScene = false;
	int sceneID = -1;

	void unload();

	void addGameObject(GameObject* gameObject);

	vector<GameObject*> getGameObjects() { return gameObjects; }

	void removeGameObject(GameObject* objToRemove);

private:
	vector<GameObject*> gameObjects;

};

