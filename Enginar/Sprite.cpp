#include "Sprite.h"
#include <iostream>
#include <unordered_map>

using namespace std;

Sprite::Sprite() : frameWaitInterval(250), currentLayer(), currentTexture() {};

TextureNode* Sprite::createTextureNode(const char* _path)
{
    TextureNode* _textureNode = nullptr;
    _textureNode = new TextureNode();
    _textureNode->texture = _path;
    
    return _textureNode;
};

Layer* Sprite::createLayer(const char* layerName, TextureNode* headTextureNode)
{
    Layer* _layer = nullptr;
    _layer = new Layer();
    _layer->head = headTextureNode;
    _layer->tail = headTextureNode;
    
    layers[layerName] = *_layer;
    return _layer;
};

Layer* Sprite::createLayer(const char* layerName, const char* texturePaths[])
{
    Layer* _layer = nullptr;
    _layer = new Layer();
    // for (const char* item : texturePaths) this->add(_layer, item);
    for (int i = 0; i < 5; i++)
    {
        TextureNode* _texture = this->createTextureNode(texturePaths[i]);
        this->add(_layer, _texture);
        cout << _layer->head->texture << endl;
    }
    layers[layerName] = *_layer;
    return _layer;
};

void Sprite::add(Layer* layer, TextureNode* texture)
{
    if (layer->head == NULL) 
    {
        layer->head = texture;
        layer->tail = texture;
    }
    else 
    {
        layer->tail->next = texture;
        layer->tail = texture;
    }
};

void Sprite::add(Layer* layer, const char* texturePath)
{
    TextureNode _texture = { texture: texturePath };
    this->add(layer, &_texture);
};


void Sprite::setCurrentLayer(Layer* layer)
{
    currentLayer = layer;
    currentTexture = layer->head;
};

void Sprite::setCurrentLayer(const char* layerName)
{
    if(layers.count(layerName))
    {
        Layer* _layer = &layers[layerName];
        this->setCurrentLayer(_layer);
    };
};

void Sprite::getInfo(){
    for (auto item : layers)
        cout << item.first << " head: " << item.second.head << endl;
};