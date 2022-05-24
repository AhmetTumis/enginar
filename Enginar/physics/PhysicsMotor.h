#pragma once
class PhysicsMotor
{
public:
	inline static PhysicsMotor* instance;
	inline static PhysicsMotor* getInstance()
	{
		return instance;
	}

	PhysicsMotor();

	void update();
};

