#pragma once
#include "Texture.h"

/* TODO */
class Sprite
{
public:
    struct TextureNode{ // "image_001.png" -> "image_002" -> ... -> "image_001.png"
        Texture texture;
        struct TextureNode *next;
    };

    struct Layer // contains circular linked list of TextureNodes
    {
        struct Layer *parent; // can be null
        TextureNode head;
    };

	void init(); // creates main head layer (with its parent=null)
    
    TextureNode createTextureNode(const char* _path);
    TextureNode createTextureNode();

    Layer createLayer();
    Layer createLayer(const char* _paths[]);

    // ADD to Layer
    bool add(Layer head, const char* _path, int index=-1);          // TEST add single 
    bool add(Layer head, TextureNode texture, int index=-1);        // add single TextureNode to layer head, -1 end
    bool add(Layer head, TextureNode* textureList[], int index=-1); // add list of TextureNode to layer head, -1 end
	
    bool addLayer(Layer head, Layer layer);                 // create layer
    bool addLayer(Layer head, TextureNode* textureList[]);  // create layer with list of TextureNodes
    bool addLayer(Layer head, const char* _paths[]);        // TEST create layer with list of image paths

    void getInfo();                 // Print head layer and its children 
    void getLayerInfo(Layer layer); // Print layer and its childen

    int getCount() const;

    void clear(Layer layer); // clear layer
    void clearAll();         // clear all
};
