#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SFML/Window.hpp>

#include "caveman.h"
#include "action.h"

class Game {
private:
    sf::RenderWindow& window;

    std::vector<Caveman> tribe;
    std::vector<Action*> actions;

    GameState management;
    GameState roundEnd;

public:
    Game() = delete;
    explicit Game(sf::RenderWindow& windowRef);
    ~Game();

    void run();

    void addCaveman();
    void removeCaveman(short id);

    void addAction(Action* action);
    void stopResearch();

    friend GameState;
};

#endif
