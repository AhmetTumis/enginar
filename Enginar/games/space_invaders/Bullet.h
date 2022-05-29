#pragma once

#include "../../common/GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(Scene* scene, bool isUp);

	void update() override;

	void OnCollide(GameObject* other) override;

private:
	int16_t dir;
};