#pragma once

#include "../common/Constants.h"
#include "../common/Vector.h"
#include "../common/EnginarMath.h"

class RigidBody
{
public:
	RigidBody() {
		mass = 1;//PhysicsConstants::UNIVERSAL_MASS;
		gravity = 9;//PhysicsConstants::GRAVITY;
	}
	/// <summary>
	/// Constructor with custom mass and gravity
	/// </summary>
	/// <param name="_mass"></param>
	/// <param name="_gravity"></param>
	RigidBody(float _mass, float _gravity = 9) {
		mass = _mass;
		gravity = _gravity;
	}

	inline void setMass(float _mass) { mass = _mass; }
	inline void setGravity(float _gravity) { gravity = _gravity; }

	inline void applyForce(vector2 _force) { force = _force; }
	inline void resetForce() { force = VEC2_ZERO; }

	inline void applyFriction(vector2 _friction) { friction = _friction; }
	inline void resetFriction() { friction = VEC2_ZERO; }

	void update(float deltaTime) 
	{
		acceleration.x = (force.x + friction.x) / mass;
		acceleration.y = (-gravity + force.y) / mass;
		
		velocity.x += acceleration.x * deltaTime;
		velocity.y -= acceleration.y * deltaTime;

		resetForce();
	}

	inline vector2& getVelocity() { return velocity; }

private:
	float mass;
	float gravity;

	vector2 force;
	vector2 friction;

	vector2 position;
	vector2 velocity;
	vector2 acceleration;
};

