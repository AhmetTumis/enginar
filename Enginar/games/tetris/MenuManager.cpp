#include "MenuManager.h"
#include "../../io/InputManager.h"
#include "../../physics/Raycast.h"
#include "../../common/Game.h"
#include "../../common/SceneManager.h"

void MenuManager::update()
{
	GameObject::update();

	auto col = (any_cast<Collider*>(playButtonGO->getComponent(typeid(Collider*))));


	if (Raycast::getInstance()->Cast((dynamic_cast<BoxCollider*>(col))))
	{
		SceneManager::getInstance()->loadScene(gameScene);
	}
}

void MenuManager::createUI(Scene* gs)
{
	gameScene = gs;

	playButtonGO = new GameObject();

	Texture* playButtonTexture = new Texture("assets/playButton.png");
	playButtonGO->addComponent(make_any<Texture*>(dynamic_cast<Texture*>(playButtonTexture)));
	playButtonGO->init(myScene);
	playButtonGO->getTransform()->setScale(new vector2(300, 150));
	playButtonGO->getTransform()->setPosition(new vector2(Game::getInstance()->getWindow()->getWindowSize().x / 2 - playButtonGO->getTransform()->getScaleX() / 2, 0));

	BoxCollider* col = new BoxCollider("block", 0, 0, .99f, .99f, playButtonTexture);
	playButtonGO->addComponent(make_any<Collider*>(dynamic_cast<Collider*>(col)));
}
