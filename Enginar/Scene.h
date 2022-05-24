#pragma once
#include "common/GameObject.h"
class Scene
{
public:
	bool isActiveScene = false;
	int sceneID = -1;

	void unload();

	void addGameObject(GameObject* gameObject);

	vector<GameObject*> getGameObjects() { return gameObjects; }

private:
	vector<GameObject*> gameObjects;

};

