#ifndef WINSCREEN_H
#define WINSCREEN_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"

/**
* Winning Screen
*/
class WinScreen : public GameState {
private:

public:
    WinScreen() = delete;
    /**
     * Constructs background and menu options, new game and exit.
     */
    explicit WinScreen(Game& gameRef);

    /**
    * Displays the winning screen.
    */
    void display(sf::RenderWindow& win);

    void additionalResizes();
};

#endif