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
	if (component.type() == typeid(Sprite*))
	{
		spriteComponent = any_cast<Sprite*>(component);
		textureComponent = spriteComponent->currentTexture->texture;
	}
	if (component.type() == typeid(Collider*))
	{
		colliderComponent = any_cast<Collider*>(component);
	}
}

any GameObject::getComponent(const type_info& componentType)
{
	if (componentType == typeid(Transform*))
	{
		return (transformComponent);
	}
	if (componentType == typeid(Collider*))
	{
		return (colliderComponent);
	}
}

void GameObject::update() 
{
	if (textureComponent != nullptr && transformComponent != nullptr)
	{
		if (spriteComponent != nullptr)
		{
			textureComponent = spriteComponent->currentTexture->texture;
			spriteComponent->currentTexture->texture->render = false;
			spriteComponent->currentTexture = spriteComponent->currentTexture->next;
			spriteComponent->currentTexture->texture->render = true;

			colliderComponent->colliderRect = spriteComponent->currentTexture->texture->textureRect;
		}

		textureComponent->textureRect = transformComponent->rect1;
		textureComponent->rotation = transformComponent->getRotation();
	}
}
