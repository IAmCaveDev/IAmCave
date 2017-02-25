#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "action.h"

class Management : public GameState {
private:
    Action* currentAction;
public:
    Management() = delete;
    explicit Management(Game& gameRef);

    void setCurrentAction(Action* newaction);
    Action& getCurrentAction();
    void pushCurrentAction();

    void display(sf::RenderWindow& win);
};

#endif
