#include "MenuManager.h"
#include "../../io/InputManager.h"
#include "../../physics/Raycast.h"
#include "../../common/Game.h"
#include "../../common/SceneManager.h"
#include "../../graphics/Text.h"
#include "../../io/DataManager.h"

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
	DataManager* dm = new DataManager();

	gameScene = gs;

	playButtonGO = new GameObject();

	Texture* playButtonTexture = new Texture("assets/playButton.png");
	playButtonGO->addComponent(make_any<Texture*>(dynamic_cast<Texture*>(playButtonTexture)));
	playButtonGO->init(myScene);
	playButtonGO->getTransform()->setScale(new vector2(.25f, .25f));
	playButtonGO->getTransform()->setPosition(new vector2(100, 250));

	BoxCollider* col = new BoxCollider("block", 0, 0, .99f, .99f, playButtonTexture);
	playButtonGO->addComponent(make_any<Collider*>(dynamic_cast<Collider*>(col)));

	auto scoreText = new GameObject();
	scoreText->init(myScene);

	Text* t = new Text("test");

	t->init(("High Score: "+ std::to_string(DataManager::getInstance()->ReadInt("highscore"))).c_str(), "assets/Marker Felt.ttf", 24, SDL_Rect{0,0,200,50});
	scoreText->addComponent(make_any<Text*>(dynamic_cast<Text*>(t)));
}
