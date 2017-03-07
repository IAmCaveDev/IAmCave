#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "button.h"
#include "rectangle.h"
#include "game.h"


class GameState {
protected:
    Game& game;

    std::vector<Rectangle*> rectangles;
    std::vector<Button*> buttons;

    EGamestates nextState;

public:
    GameState() = delete;
    explicit GameState(Game& gameRef);
    ~GameState();

    void onResize();

    std::vector<Button*>& getButtons();
    std::vector<Rectangle*>& getRectangles();

    virtual void display(sf::RenderWindow& win) = 0;

    EGamestates getNextState();
    void setNextState(EGamestates newNextState);
};

#endif
