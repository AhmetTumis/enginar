#pragma once

#include "../common/GameObject.h"

class Raycast
{
public:
	Raycast();

	inline static Raycast* instance;
	inline static Raycast* getInstance()
	{
		return instance;
	}

	bool Cast(BoxCollider* go);
};

