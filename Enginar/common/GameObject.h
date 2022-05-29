#pragma once
#define SDL_MAIN_HANDLED
#include <any>
#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"
#include "../graphics/Texture.h"
#include "../graphics/Sprite.h"
#include "../physics/Collider.h"
#include "../physics/RigidBody.h"
#include "Scene.h"
#include "../graphics/Text.h"

using namespace std;
class Transform;
class Scene;

class GameObject
{
public:
	~GameObject();

	void Destroy();

	const char* name = "";

	bool isActive;

	void init(Scene* scene);
	Transform* getTransform();
	Texture* getTexture();
	Text* getText();
	void addComponent(any component);
	any getComponent(const type_info& componentType);
	virtual void update();
	void updateTexture(bool willRender);
	RigidBody* rigidbodyComponent = nullptr;
	GameObject* parent = nullptr;
	vector<GameObject*> children;

	vector2* movementDelta = nullptr;
	void setMovementDelta(vector2 delta)
	{
		*movementDelta = delta;
	}

	bool isColliding = false;

	virtual void OnCollide(GameObject* other) 
	{
		if (std::find(collidedGameObjects.begin(), collidedGameObjects.end(), other) == collidedGameObjects.end())
		{
			collidedGameObjects.push_back(other);
			isColliding = true;

		}
	}
	virtual void StopColliding(GameObject* other) 
	{
		if (std::find(collidedGameObjects.begin(), collidedGameObjects.end(), other) != collidedGameObjects.end())
		{
			collidedGameObjects.erase(std::remove(collidedGameObjects.begin(), collidedGameObjects.end(), other), collidedGameObjects.end());
			isColliding = collidedGameObjects.size() > 0;
		}
	}
private:
	Texture* textureComponent = nullptr;
	Sprite* spriteComponent = nullptr;
	Transform* transformComponent = nullptr;
	Collider* colliderComponent = nullptr;
	Text* textComponent = nullptr;

	vector<GameObject*> collidedGameObjects;

protected:
	bool willUpdateTexture = true;
	Scene* myScene = nullptr;
};

