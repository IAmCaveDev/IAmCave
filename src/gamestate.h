#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "button.h"
#include "rectangle.h"
#include "caveman.h"

class GameState {
protected:
    std::vector<Rectangle*> rectangles;
    std::vector<Button*> buttons;

    std::vector<Caveman*>& tribe;

public:
    GameState();
    explicit GameState(std::vector<Caveman*>& newTribe);
    ~GameState();

    void onResize();

    std::vector<Button*>& getButtons();
    std::vector<Rectangle*>& getRectangles();

    virtual void display(sf::RenderWindow& win) = 0;
};

#endif
