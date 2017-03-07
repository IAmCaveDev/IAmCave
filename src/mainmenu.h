#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"

class MainMenu : public GameState {
private:

public:
    MainMenu() = delete;
    explicit MainMenu(sf::RenderWindow& win);

    void display(sf::RenderWindow& win);
};

#endif
