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
		spriteComponent->startUpdate();
		textureComponent = spriteComponent->currentTexture->texture;
	}
	if (component.type() == typeid(Collider*))
	{
		colliderComponent = any_cast<Collider*>(component);
	}
	if (component.type() == typeid(RigidBody*))
	{
		rigidbodyComponent = any_cast<RigidBody*>(component);
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
			//update sprite frame
			spriteComponent->update();

			//equalize current texture to our textureComponent
			textureComponent = spriteComponent->currentTexture->texture;
		}

		//update collider shape according to texture shape
		colliderComponent->updateShape(textureComponent);

		if (rigidbodyComponent != nullptr)
		{
			rigidbodyComponent->update(.1f);
			auto a = *(transformComponent->getPosition());
			transformComponent->setPosition(&(*(transformComponent->getPosition()) + rigidbodyComponent->getVelocity()));
		}

		//update texture rect according to transform rect
		textureComponent->textureRect = transformComponent->rect1;
		textureComponent->rotation = transformComponent->getRotation();
	}
}
