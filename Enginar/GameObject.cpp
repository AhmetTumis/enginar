#include "GameObject.h"
#include "Texture.h"

//Transformation'� yarat�r
//Bu da i�erisinde position, rotation ve scale tutar
void GameObject::init()
{
	AddComponent(make_any<Transform*>(new Transform()));
}

void GameObject::AddComponent(any component)
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
