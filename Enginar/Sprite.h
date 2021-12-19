#pragma once
#include <unordered_map>

using namespace std;

struct TextureNode
{
    const char* texture;
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
    Layer* createLayer(const char* layerName, const char* texturePaths[]);

    void add(Layer* layer, TextureNode* texture);
    void add(Layer* layer, const char* texturePath);
    void add(Layer* layer, const char* textures[]);

    void addLayer(Layer* parent, Layer* layer); // simdilik isimiz yok.

    void setCurrentLayer(Layer* layer);
    void setCurrentLayer(const char* layerName);

    void getInfo();
    void getLayerInfo(Layer layer);

    void clear(Layer layer);
    void clearAll();
};
