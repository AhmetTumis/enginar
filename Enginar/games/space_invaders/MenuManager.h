#pragma once

#include "../../common/GameObject.h"
class MenuManager : public GameObject
{
public:
	void update();
	void createUI(Scene* gs);

	Scene* gameScene = nullptr;
private:
	GameObject* playButtonGO = nullptr;
};

