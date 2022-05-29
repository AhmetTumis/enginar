#pragma once

#include "../../common/GameObject.h"

class Ship : public GameObject
{
public:
	Ship(Scene* scene, const char* texturePath, bool isEnemy, float _health, float _dmg) 
	{
		init(scene);

		Texture* shipTexture = new Texture(texturePath);
		addComponent(make_any<Texture*>(dynamic_cast<Texture*>(shipTexture)));

		if (isEnemy)
		{
			BoxCollider* col = new BoxCollider(isEnemy ? "enemy" : "player", 0, 0, .99f, .99f, shipTexture);
			addComponent(make_any<Collider*>(dynamic_cast<Collider*>(col)));
		}

		getTransform()->setScale(.05f);

		this->health = _health;
		this->dmg = _dmg;
	}

protected:
	float health = 0;
	float dmg = 0;

	int cooldown = 100;
};

class PlayerShip : public Ship
{
public:
	PlayerShip(Scene* scene) :Ship(scene ,"assets/spaceship.png", false, 100, 10) {}

	void update() override;
};

class EnemyShip : public Ship
{
public:
	EnemyShip(Scene* scene, const char* _path ,float _health, float _dmg) :Ship(scene, _path, true, _health, _dmg) {}

	void update() override;
};

class EnemyShipA : public EnemyShip
{
public:
	EnemyShipA(Scene* scene) :EnemyShip(scene, "assets/enemyA.png", 20, 5) {}
};

class EnemyShipB : public EnemyShip
{
public:
	EnemyShipB(Scene* scene) :EnemyShip(scene, "assets/enemyB.png", 10, 10) {}
};