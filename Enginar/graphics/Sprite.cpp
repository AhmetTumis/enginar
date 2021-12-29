#include "Sprite.h"

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

Layer* Sprite::createLayer(const char* layerName, vector<const char*> texturePaths)
{
    Layer* _layer = nullptr;
    _layer = new Layer();
    for (auto texturePath : texturePaths)
    {
        TextureNode* _texture = this->createTextureNode(texturePath);
        this->add(_layer, _texture);
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
        texture->next = layer->tail->next;
        layer->tail->next = texture;
        layer->tail = texture;
        layer->tail->next = layer->head;
    }
};

void Sprite::add(Layer* layer, const char* _path)
{
    TextureNode* _texture = this->createTextureNode(_path);
    this->add(layer, _texture);
};

void Sprite::add(const char* layerName, const char* _path)
{
    if(layers.count(layerName))
    {
        Layer* _layer = &layers[layerName];
        this->add(_layer, _path);
    };
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