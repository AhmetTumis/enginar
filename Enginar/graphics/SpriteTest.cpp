#include <iostream>
#include <vector>
#include "Sprite.h"

using namespace std;

int mainn()
{
    Sprite playerAdventurer = Sprite();
    
    vector<const char*> idleSprites = {
        "assets/adventurer-idle-2-00.png",
        "assets/adventurer-idle-2-01.png",
        "assets/adventurer-idle-2-02.png",
        "assets/adventurer-idle-2-03.png",
    };
    
    Layer* layerIDLE = playerAdventurer.createLayer("IDLE", idleSprites);

    playerAdventurer.add(layerIDLE, "assets/adventurer-idle-2-XX.png");
    playerAdventurer.setCurrentLayer("IDLE");
    
    // Layer sprite dosyalari tamamlandi, render kisminda bize lazim olacak tek sey "playerAdventurer.currentTexture"
    // sonra next next
    // baktin layer degisti, currentTexture de degisti
    TextureNode* cur = playerAdventurer.currentTexture;

    int i = 0;
    while(i < 16){
        cout << i << "\t" << cur->texture << endl; // cur = playerAdventurer.currentTexture
        cur = cur->next;
        i++;
    }
    
    return 0;
}
