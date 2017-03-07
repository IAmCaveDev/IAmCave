#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "action.h"
#include "verticalbuttonlist.h"

class Management : public GameState {
private:
    Action* currentAction;

    VerticalButtonList* actionDisplay;

public:
    Management() = delete;
    explicit Management(Game& gameRef);

    void setCurrentAction(EActions newaction, short duration);
    Action& getCurrentAction();
    void pushCurrentAction();
    void deleteCurrentAction();

    std::vector<Caveman*> getIdlingTribe();
    VerticalButtonList& getActionDisplay();

    void display(sf::RenderWindow& win);
};

#endif
