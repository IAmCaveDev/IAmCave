#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "game.h"

class GameState {
private:
    Game& game;
    std::vector<sf::Drawable> drawables;

public:
    GameState() = delete;
    explicit GameState(Game& gameRef);
};

#endif
