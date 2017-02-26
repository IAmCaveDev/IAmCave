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

    Textbox* beforeColumn;
    Textbox* afterColumn;

public:
    RoundEnd() = delete;
    explicit RoundEnd(Game& gameRef);

    void step();

    void display(sf::RenderWindow& win);
};

#endif
