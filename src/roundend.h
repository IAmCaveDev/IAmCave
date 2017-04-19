#ifndef ROUNDEND_H
#define ROUNDEND_H

#include <SFML/Graphics.hpp>
#include <random>

#include "gamestate.h"
#include "textbox.h"
#include "action.h"
#include "textbox.h"

/**
 * The end of a round.
 * Displays information about the round.
 */
class RoundEnd : public GameState {
private:
    std::mt19937 rng;

    Textbox* infoColumn;

    Textbox* textbox;

    /**
    * Calls the resolve function of nextAction and adds to Gameresources
    */
    void resolveActions();

    /**
     * Passive resource consumption
     */
    void doPassives();

    void doEvents(Resources resourcesBefore);

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

    /**
     * Sets the text of the state's textbox.
     */
    void setTextboxText(std::string str);

    void additionalResizes();
};

#endif
