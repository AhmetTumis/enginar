#include "Block.h"
#include "Piece.h"

void Block::OnCollide(GameObject* other)
{
	GameObject::OnCollide(other);
	if ((dynamic_cast<Piece*>(parent))->placed)
	{
		return;
	}
	printf("collision!");
	(dynamic_cast<Piece*>(parent))->Place();
}
