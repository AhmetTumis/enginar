#include "Scene.h"

void Scene::unload()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Destroy();
	}
}

void Scene::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void Scene::removeGameObject(GameObject* objToRemove)
{
	for (auto obj : gameObjects)
	{
		if (obj == objToRemove)
		{
			gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), obj), gameObjects.end());
			break;
		}
	}
}
