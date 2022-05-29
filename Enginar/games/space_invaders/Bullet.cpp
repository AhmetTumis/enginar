#include "Bullet.h"
#include "GameManager.h"
#include "../../io/DataManager.h"

Bullet::Bullet(Scene* scene, bool isUp)
{
	init(scene);

	Texture* shipTexture = new Texture("assets/bullet.png");
   	addComponent(make_any<Texture*>(dynamic_cast<Texture*>(shipTexture)));

	BoxCollider* col = new BoxCollider("bullet", 0, 0, .99f, .99f, shipTexture);
	addComponent(make_any<Collider*>(dynamic_cast<Collider*>(col)));

	getTransform()->setScale(.1f);

	dir = isUp ? -1 : 1;
}

void Bullet::update()
{
	GameObject::update();
	GameObject::getTransform()->setPositionY(getTransform()->getPositionY() + dir);
}

void Bullet::OnCollide(GameObject* other)
{
	GameObject::OnCollide(other);
	auto col = (any_cast<Collider*>(other->getComponent(typeid(Collider*))));
	if (col->tag == "enemy")
	{
		Destroy();
		other->Destroy();

		GameManager::getGO()->score++;
		if (DataManager::getInstance()->ReadInt("highscore") < GameManager::getGO()->score)
		{
			DataManager::getInstance()->SaveInt("highscore", GameManager::getGO()->score);
		}

		GameManager::getGO()->scoreText->getText()->setText(("Score: " + std::to_string(GameManager::getGO()->score)).c_str());
	}
}