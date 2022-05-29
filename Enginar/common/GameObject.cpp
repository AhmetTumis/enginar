#include "GameObject.h"
#include "../graphics/Texture.h"
#include "Game.h"

GameObject::~GameObject()
{
	if (spriteComponent != nullptr)
	{
		
	}
	else 
	{
		if (textureComponent != nullptr)
		{
			textureComponent->render = false;
		}
	}
}

void GameObject::Destroy()
{
	for (auto other : collidedGameObjects)
	{
		other->StopColliding(this);
	}

	isActive = false;

	if (textureComponent != nullptr)
	{
		textureComponent->render = false;
	}

	//myScene->removeGameObject(this);

	//delete this;
}

//Transformation'� yarat�r
//Bu da i�erisinde position, rotation ve scale tutar
void GameObject::init(Scene* scene)
{
	isActive = true;

	scene->addGameObject(this);
	myScene = scene;

	addComponent(make_any<Transform*>(new Transform()));
	movementDelta = new vector2(0, 0);
}

Transform* GameObject::getTransform()
{
	return transformComponent;
}

Texture* GameObject::getTexture()
{
	return textureComponent;
}

Text* GameObject::getText()
{
	return textComponent;
}

void GameObject::addComponent(any component)
{
	if (component.type() == typeid(Transform*))
	{
		transformComponent = any_cast<Transform*>(component);
		transformComponent->setOwner(this);
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
	if (component.type() == typeid(Text*))
	{
		textComponent = any_cast<Text*>(component);
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
		if (colliderComponent != nullptr)
		{
			colliderComponent->updateShape(textureComponent);

		}

		if (rigidbodyComponent != nullptr)
		{
			rigidbodyComponent->update(.1f);
			auto a = *(transformComponent->getPosition());
			transformComponent->setPosition(&(*(transformComponent->getPosition()) + rigidbodyComponent->getVelocity()));
		}

		if (parent != nullptr)
		{
			updateTexture(parent->willUpdateTexture);
		}
		else
		{
			updateTexture(willUpdateTexture);
		}
	}
}

void GameObject::updateTexture(bool willUpdate)
{
	if (textureComponent != nullptr && transformComponent != nullptr)
	{
		SDL_Rect texRect = SDL_Rect();
		texRect.x = transformComponent->rect1.x;
		texRect.y = transformComponent->rect1.y;
		texRect.w = transformComponent->getScaleX() * textureComponent->defaultTextureWidth;
		texRect.h = transformComponent->getScaleY() * textureComponent->defaultTextureHeight;
		if (willUpdate)
		{
			//update texture rect according to transform rect

			textureComponent->textureRect = texRect;
			textureComponent->rotation = transformComponent->getRotation();
		}
		textureComponent->physicsRect = texRect;
	}

}