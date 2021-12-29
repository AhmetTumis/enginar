#include "GameObject.h"
#include "../graphics/Texture.h"

//Transformation'� yarat�r
//Bu da i�erisinde position, rotation ve scale tutar
void GameObject::init()
{
	addComponent(make_any<Transform*>(new Transform()));
}

void GameObject::addComponent(any component)
{
	if (component.type() == typeid(Transform*))
	{
		transformComponent = any_cast<Transform*>(component);
	}
	if (component.type() == typeid(Texture*))
	{
		textureComponent = any_cast<Texture*>(component);
		textureComponent->init();
	}
}

void GameObject::update() 
{
	if (textureComponent != nullptr && transformComponent != nullptr)
	{
		textureComponent->textureRect = transformComponent->rect1;
		textureComponent->rotation = transformComponent->getRotation();

	}
}
