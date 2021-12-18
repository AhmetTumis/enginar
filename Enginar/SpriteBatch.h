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

	void init(); // also creates main layer, both for static and dynamic sprites.

    bool add(Layer head, TextureNode texture);
    bool add(Layer head, int index, TextureNode texture);  
	bool addLayer(Layer head, Layer layer);

    int getCount() const;

    void clear(Layer layer); // clear layer
    void clearAll();         // clear all
};
