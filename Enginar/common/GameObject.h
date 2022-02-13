#pragma once

#include <any>
#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"
#include "../graphics/Texture.h"
#include "../graphics/Sprite.h"
#include "../physics/Collider.h"

using namespace std;

class GameObject
{
public:
	void init();
	Transform* getTransform() { return transformComponent; };
	void addComponent(any component);
	any getComponent(const type_info& componentType);
	void update();

private:
	Texture* textureComponent = nullptr;
	Sprite* spriteComponent = nullptr;
	Transform* transformComponent = nullptr;
	Collider* colliderComponent = nullptr;
};

