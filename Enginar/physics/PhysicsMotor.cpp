#include "PhysicsMotor.h"
#include "Collision.h"
#include "../entrypoint.h"

PhysicsMotor::PhysicsMotor()
{
	instance = this;
	raycast = new Raycast();
}

//Calculate all the possible collisions
void PhysicsMotor::update()
{
	auto scene = Game::getInstance()->getActiveScene();

	for (auto gameObject1 : scene->getGameObjects())
	{
		auto colA = (any_cast<Collider*>(gameObject1->getComponent(typeid(Collider*))));

		if (gameObject1->isActive == false || colA == nullptr)
		{
			continue;
		}

		auto colTypeA = colA->GetType();

		for (auto gameObject2 : scene->getGameObjects())
		{
			if (gameObject1 != gameObject2 && ((gameObject1->parent != nullptr && gameObject1->parent != gameObject2->parent) || (gameObject1->parent == nullptr)))
			{
				auto colB = (any_cast<Collider*>(gameObject2->getComponent(typeid(Collider*))));
				if (gameObject2->isActive == false || colB == nullptr)
				{
					continue;
				}
				auto colTypeB = colB->GetType();

				bool isColliding = false;

				if (colTypeA == colTypeB)
				{
					if (colTypeA == Collider::ColliderType::BOX)
					{
						isColliding = Collision::isCollidingAABB(*dynamic_cast<BoxCollider*>(colA), *dynamic_cast<BoxCollider*>(colB));
					}
					else
					{
						isColliding = Collision::isCollidingCircleAndCircle(*dynamic_cast<CircleCollider*>(colA), *dynamic_cast<CircleCollider*>(colB));
					}

					if (isColliding)
					{
						gameObject1->OnCollide(gameObject2);
						gameObject2->OnCollide(gameObject1);
					}
					else 
					{
						gameObject1->StopColliding(gameObject2);
						gameObject2->StopColliding(gameObject1);
					}
				}
			}
		}
	}
}
