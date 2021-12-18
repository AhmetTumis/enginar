#include "SpriteBatch.h"

void Sprite::Sprite()
{
    Layer parent = {
        parent: nullptr,
        head: nullptr
    }
}

TextureNode Sprite::createTextureNode(const char* _path, TextureNode* next=nullptr)
{
    TextureNode _texture = {
        texture: Texture(_path),
        next: next
    }
    return _texture;
}

Layer Sprite::createLayer(const char* _path=nullptr)
{
    Layer _layer = {
        parent: nullptr,
        head: createTextureNode(this->createTextureNode(_path)) // Şu anki haliyle hata vermesi lazım
    }
}
