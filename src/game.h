#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "caveman.h"
#include "action.h"
#include "gamestate.h"

class Game {
private:
    sf::RenderWindow& window;

    std::vector<Caveman> tribe;
    std::vector<Action*> actions;
    std::vector<Action*> queuedActions;

    GameState* currentGameState;
    GameState management;
    GameState roundEnd;

    bool active;

public:
    Game() = delete;
    explicit Game(sf::RenderWindow& windowRef);

    void update();

    void addCaveman();
    void removeCaveman(short id);

    void addAction(Action* action);
    void stopResearch();

    const GameState& getCurrentGameState() const;

    bool isActive() const;
    void setActive(bool newActive);

    friend GameState;
};

#endif
