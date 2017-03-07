#ifndef GAME_H
#define GAME_H

#include <vector>

#include "caveman.h"
#include "action.h"
#include "caveman.h"

struct Resources {
    float food;
    int buildingMaterial;
    int cavemanCapacity;
};

class Game {
private:
    unsigned int roundNumber = 0;

    std::vector<Caveman*> tribe;
    std::vector<Action*> actions;

    Resources resources;

public:
    Game();

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
};

#endif
