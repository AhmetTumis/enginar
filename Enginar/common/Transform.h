#pragma once
#include "EnginarMath.h"
#include "GameObject.h"
#include "vector.h"
#include <SDL_video.h>
#include <math.h>

#define PI 3.14159265

class GameObject;

class Transform
{
public:
	Transform();

	float posX, posY;

	//position setters
	void setPosition(vector2* newPosition);
	void setPositionX(float x);
	void setPositionY(float y);
	//scale setters
	void setScale(float size);
	void setScale(vector2* newScale);
	void setScaleX(float x);
	void setScaleY(float y);
	//rotation setter
	void setRotation(int r);

	//position getters
	inline vector2* getPosition() { return position; };
	inline float getPositionX() { return position->x; };
	inline float getPositionY() { return position->y; };
	inline vector2* getForward()
	{
		return forward;
	}
	inline vector2* getUp()
	{
		return up;
	}

	//scale getters
	inline vector2* getScale() { return scale; };
	inline float getScaleX() { return scale->x; };
	inline float getScaleY() { return scale->y; };

	//rotation getter
	inline int getRotation() { return rotation; };

	SDL_Rect rect1;

	GameObject* getOwner() { return ownerGameObject; }
	void setOwner(GameObject* owner) { ownerGameObject = owner; }

private:
	vector2* position;
	vector2* forward;
	vector2* up;
	vector2* scale;
	int rotation = 0;

	GameObject* ownerGameObject = nullptr;

};

