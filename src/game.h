#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "caveman.h"
#include "action.h"
#include "gamestate.h"
#include "mainmenu.h"
#include "management.h"
#include "roundend.h"
#include "caveman.h"

enum EGamestates{
    mainMenu,
    management,
    roundEnd
};

struct Resources {
    float food;
    int buildingMaterial;
    int cavemanCapacity;
};

class Game {
private:
    sf::RenderWindow& window;

    std::vector<Caveman*> tribe;
    std::vector<Action*> actions;
    std::vector<Action*> queuedActions;

    GameState* currentGameState;
    Management management;
    RoundEnd roundEnd;
    MainMenu mainMenu;

    Resources resources;

public:
    Game() = delete;
    explicit Game(sf::RenderWindow& windowRef);

    void display();

    void addCaveman(int maxAge = 50, int minAge = 0);
    void removeCaveman(short id);
    std::vector<Caveman*>& getTribe();

    void addActiontoQueue(Action* newaction);
    void stopResearch();

    GameState& getCurrentGameState();
    void setCurrentGameState(EGamestates newstate);

    Resources& getResources();

    sf::RenderWindow& getWindow();

    friend GameState;
};

#endif
