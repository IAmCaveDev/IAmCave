#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

#include "cavemanfactory.h"
#include "actionfactory.h"

/**
 * Resource data.
 */
struct Resources {
    float food;
    int buildingMaterial;
    int cavemanCapacity;
};

/**
 * Stores data about a game.
 * Data stored here is used for calculations and displaying. Every function that
 * modifies anything concerning the game should modify this object.
 */
class Game {
private:
    unsigned int roundNumber = 0;

    std::vector<std::unique_ptr<Caveman>> tribe;
    std::vector<std::unique_ptr<Action>> actions;

    Resources resources;

public:
    /**
     * Default constructor for game.
     * Constructs five Caveman objects with age five and adds them to tribe.
     * Sets initial resources to 200 food, 50 building material and 10 caveman
     * capacity.
     * /todo Add a constructor that loads it's data from a savefile.
     */
    Game();

    /**
     * Adds a caveman to the tribe.
     * @param maxAge The maximum age allowed of the caveman.
     * @param minAge The minimum age allowed of the caveman.
     */
    void addCaveman(int maxAge = 50, int minAge = 0);
    /**
     * Removes a caveman from the tribe.
     * @param id The id of the caveman to be removed.
     */
    void removeCaveman(short id);

    void addAction(std::unique_ptr<Action> newAction);
    void removeAction(int id);
    std::vector<std::unique_ptr<Action>>& getActions();
    void addToResources(Resources amount);
    void stopResearch();

    /**
     * Returns a reference to the tribe.
     */
    std::vector<std::unique_ptr<Caveman>>& getTribe();

    /**
     * Returns a reference to the tribe.
     */
    Resources& getResources();

    /**
     * Returns the curren round number.
     */
    unsigned int getRoundNumber();
    /**
     * Increases the round number.
     * @param n Increment.
     */
    void increaseRoundNumber(unsigned int n = 1);
};

#endif
