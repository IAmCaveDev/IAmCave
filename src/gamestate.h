#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "button.h"

// cyclic dependency otherwise
class Game;

class GameState {
protected:
    Game& game;
    std::vector<sf::Drawable*> drawables;
    std::vector<Button*> buttons;

public:
    GameState() = delete;
    explicit GameState(Game& gameRef);
    ~GameState();

    std::vector<Button*>& getButtons();
    std::vector<sf::Drawable*>& getDrawables();
};

#endif
