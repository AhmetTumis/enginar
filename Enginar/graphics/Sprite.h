#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>
#include "Texture.h"

using namespace std;

struct TextureNode
{
    const char* texturePath;
    Texture* texture;
    struct TextureNode* next;
};

struct Layer
{
    struct Layer* parent;
    TextureNode* head;
    TextureNode* tail;
};

class Sprite
{
public:
    std::unordered_map<const char*, Layer> layers;
    Layer* currentLayer;
    TextureNode* currentTexture; 
    int frameWaitInterval;

    Sprite();

    TextureNode* createTextureNode(const char* _path);
    Layer* createLayer(const char* layerName, TextureNode* headTextureNode);
    Layer* createLayer(const char* layerName, vector<const char*> texturePaths);

    void add(Layer* layer, TextureNode* texture);
    void add(Layer* layer, const char* texturePath);
    void add(const char* layerName, const char* _path);

    void addLayer(Layer* parent, Layer* layer); // simdilik isimiz yok.

    void setCurrentLayer(Layer* layer);
    void setCurrentLayer(const char* layerName);

    void printInfo();
    void getLayerInfo(Layer layer);

    void startUpdate();
    void update();

    void clear(Layer layer);
    void clearAll();
private:
    int t = 0;
    bool loop = false;
};