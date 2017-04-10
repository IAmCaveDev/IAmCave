#ifndef RESOURCEDISPLAY_H
#define RESOURCEDISPLAY_H

#include <string>
#include <vector>
#include "game.h"
#include "textbox.h"


class ResourceDisplay {
private:
    Game& gameRef;
    Textbox food;
    Textbox buildingMaterial;
    Textbox cavemanCapacity;
    Rectangle foodHeap;
    Rectangle materialHeap;

    void update();

public:
    ResourceDisplay(Game& game);

    void display(sf::RenderWindow& win);
    
    void onResize();
};

#endif