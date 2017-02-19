#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>

#include "game.h"
#include "button.h"

class MainMenu {
private:
    sf::RenderWindow& window;
    Game& game;

    std::vector<sf::Drawable*> drawables;
    std::vector<Button> buttons;

public:
    MainMenu() = delete;
    MainMenu(sf::RenderWindow& windowRef, Game& gameRef);

    void update();

    const std::vector<Button>& getButtons() const;
};

#endif
