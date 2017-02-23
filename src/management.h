#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"

class Management : public GameState {
private:

public:
    Management() = delete;
    explicit Management(Game& gameRef);

    void display(sf::RenderWindow& win);
};

#endif
