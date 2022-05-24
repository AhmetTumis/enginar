#include "Scene.h"

void Scene::unload()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}

void Scene::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}