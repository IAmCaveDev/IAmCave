#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "caveman.h"
#include "action.h"
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

    unsigned int roundNumber = 0;

    std::vector<Caveman*> tribe;
    std::vector<Action*> actions;

    Resources resources;

public:
    Game() = delete;
    explicit Game(sf::RenderWindow& windowRef);

    void display();

    void addCaveman(int maxAge = 50, int minAge = 0);
    void removeCaveman(short id);
    std::vector<Caveman*>& getTribe();

    void addAction(Action* newaction);
    void removeAction(int id);
    std::vector<Action*> getActions();
    void addToResources(Resources amount);
    void stopResearch();

    Resources& getResources();

    unsigned int getRoundNumber();
    void increaseRoundNumber(unsigned int n = 1);

    sf::RenderWindow& getWindow();
};

#endif
