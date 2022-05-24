#pragma once

#include "../../graphics/Texture.h"
#include "../../common/GameObject.h"
#include "../../physics/Collider.h"

class Block : public GameObject
{
public:

	Block(float posX, float posY)
	{
		init();

		Texture* blockTexture = new Texture("assets/square.png");
		addComponent(make_any<Texture*>(dynamic_cast<Texture*>(blockTexture)));

		getTransform()->setPosition(new vector2(posX * 50, posY * 50));

		getTransform()->setScale(50);

		BoxCollider* col = new BoxCollider("block", 0, 0, .99f, .99f, blockTexture);
		addComponent(make_any<Collider*>(dynamic_cast<Collider*>(col)));
	}

	void OnCollide(GameObject* other) override;
};