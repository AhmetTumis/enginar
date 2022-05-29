#pragma once

#include "Scene.h"
#include "Game.h"

class SceneManager
{
public:
	inline static SceneManager* getInstance() { return instance; }

	SceneManager();

	void loadScene(Scene* scene);

private:
	inline static SceneManager* instance;
	Game* gameInstance = nullptr;
};

