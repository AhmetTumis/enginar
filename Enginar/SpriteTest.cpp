#include <iostream>
#include "Sprite.h"

using namespace std;

int main()
{
    Sprite playerAdventurer = Sprite();
    
    const char* idleSprites[4] = {
        "assets/adventurer-idle-2-00.png",
        "assets/adventurer-idle-2-01.png",
        "assets/adventurer-idle-2-02.png",
        "assets/adventurer-idle-2-03.png",
    };
    
    Layer* layerIDLE = playerAdventurer.createLayer("IDLE", imgs);

    playerAdventurer.setCurrentLayer("IDLE");
    
    
    TextureNode* cur = sprite.currentLayer->head; // TODO: renderda hallolunasi icap olunasi
    while(cur != NULL){ // TODO: circular olacak
        cout << cur->texture << endl; // playerAdventurer.currentTexture
        cur = cur->next;
    }
    
    return 0;
}
