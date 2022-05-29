#include "Raycast.h"
#include "../io/InputManager.h"

Raycast::Raycast()
{
	instance = this;
}

//Return true if mouse is colliding with given object
bool Raycast::Cast(BoxCollider* col)
{
	auto* mousePos = InputManager::getInstance()->getMousePosition();

	if (mousePos->x > col->colliderRect.x && 
		mousePos->x < col->colliderRect.x + col->colliderRect.w && 
		mousePos->y > col->colliderRect.y &&
			mousePos->y < col->colliderRect.y + col->colliderRect.h)
	{
		return true;
	}

	return false;
}
