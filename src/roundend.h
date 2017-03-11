#ifndef ROUNDEND_H
#define ROUNDEND_H

#include <SFML/Graphics.hpp>
#include <random>

#include "gamestate.h"
#include "textbox.h"
#include "action.h"

/**
 * The end of a round.
 * Displays information about the round.
 */
class RoundEnd : public GameState {
private:
    std::mt19937 rng;

    Textbox* infoColumn;

public:
    RoundEnd() = delete;
    explicit RoundEnd(Game& gameRef);

    /**
     * Progresses by one round.
     */
    void step();

    /**
     * Displays information about the round and a button to go to the next
     * management state and begin a new round.
     */
    void display(sf::RenderWindow& win);
};

#endif
