#ifndef LOSESCREEN_H
#define LOSESCREEN_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"

/**
* Loosing Screen
*/
class LoseScreen : public GameState {
private:

public:
    LoseScreen() = delete;
    /**
    * Constructs background and menu options: new game and exit.
    */
    explicit LoseScreen(Game& gameRef);

    /**
    * Displays the loosing screen.
    */
    void display(sf::RenderWindow& win);

    void additionalResizes();
};

#endif