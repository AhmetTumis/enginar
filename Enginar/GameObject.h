#pragma once

#include <any>
#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"
#include "Texture.h"

using namespace std;

class GameObject
{
public:
	void init();
	Transform* getTransform() { return transformComponent; };
	void AddComponent(any component);
private:
	Texture* textureComponent = nullptr;
	Transform* transformComponent = nullptr;
};

