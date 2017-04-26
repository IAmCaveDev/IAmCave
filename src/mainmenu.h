#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"

/**
 * The main menu of the game.
 */
class MainMenu : public GameState {
private:
    bool eventSignEnabled;
    Button* eventSign;

public:
    MainMenu() = delete;
    /**
     * Constructs a main menu with several menu options.
     */
    explicit MainMenu(Game& gameRef);

    /**
     * Displays the menu background and Buttons.
     * @param win The window to draw on.
     */
    void display(sf::RenderWindow& win);

    void additionalResizes();

    void toggleEventSign();
};

#endif
