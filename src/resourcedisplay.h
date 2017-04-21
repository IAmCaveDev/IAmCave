#ifndef RESOURCEDISPLAY_H
#define RESOURCEDISPLAY_H

#include <string>
#include <vector>
#include "game.h"
#include "textbox.h"

/**
 * HUD used to display the amount of current Resources. 
 * Used in Management state.
 */
class ResourceDisplay {
private:
    Game& gameRef;
    Textbox food;
    Textbox buildingMaterial;
    Textbox cavemanCapacity;
    Rectangle foodHeap;
    Rectangle materialHeap;
    /**
     * Update Textboxes and Graphics for food and material Heaps
     */
    void update();

public:
    ResourceDisplay(Game& game);
    /**
     * Draws the ResourceDisplay.
     */
    void display(sf::RenderWindow& win);
    /**
     * Resizes and Repositions Textboxes and Graphics.
     */
    void onResize();
};

#endif