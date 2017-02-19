#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "caveman.h"
#include "action.h"
#include "gamestate.h"
#include "mainmenu.h"

enum EGamestates{mainMenu,management,roundEnd};

class Game {
private:
    sf::RenderWindow& window;

    std::vector<Caveman> tribe;
    std::vector<Action*> actions;
    std::vector<Action*> queuedActions;

    GameState* currentGameState;
    GameState management;
    GameState roundEnd;
    MainMenu mainMenu;

public:
    Game() = delete;
    explicit Game(sf::RenderWindow& windowRef);

    void update();

    void addCaveman();
    void removeCaveman(short id);

    void addAction(Action* action);
    void stopResearch();

    GameState& getCurrentGameState() const;
    void setCurrentGameState(EGamestates newstate);

    sf::RenderWindow& getWindow();

    friend GameState;
};

#endif
