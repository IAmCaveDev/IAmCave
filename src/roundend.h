#ifndef ROUNDEND_H
#define ROUNDEND_H

#include <SFML/Graphics.hpp>
#include <random>

#include "gamestate.h"
#include "textbox.h"
#include "action.h"

class RoundEnd : public GameState {
private:
    std::mt19937 rng;

    Textbox* infoColumn;

    Resources& resources;

public:
    RoundEnd() = delete;
    explicit RoundEnd(std::vector<Caveman*>& newTribe, Resources& newResources);

    void step(unsigned int roundNumber);

    void display(sf::RenderWindow& win);
};

#endif
