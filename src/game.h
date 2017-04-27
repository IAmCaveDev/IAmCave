#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

#include "caveman.h"
#include "action.h"
#include "techtree.h"
#include "eventfactory.h"
#include "resources.h"

/**
 * Stores data about a game.
 * Data stored here is used for calculations and displaying. Every function that
 * modifies anything concerning the game should modify this object.
 */
class Game {
private:
    unsigned int roundNumber = 0;

    std::vector<std::shared_ptr<Caveman>> tribe;
    std::vector<std::unique_ptr<Action>> actions;
    std::vector<std::shared_ptr<Event>> events;
    Techtree techtree;

    Resources resources;
    /**
     * Added up Bonuses from all researched Techs.
     */
    Tech::StatBoosts techBonuses;


    void repositionTribe();

    const int tribeLeftPadding = 150;
    const int tribeRightPadding = 750;
    const int tribeYPos = 650;
    float tribeScale = 1;
    int tribePadding = 50;

    const int normalCavemanWidth = 100;
    const int normalCavemanHeight = 200;

    bool eventsEnabled;

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
    * Adds a specific caveman to the tribe.
    * @param maxAge The maximum age allowed of the caveman.
    * @param minAge The minimum age allowed of the caveman.
    * @param newIntelligence The intelligence level of the new caveman.
    * @param newFitness The fitness level of the new caveman.
    * @param newIsMale Decides the gender of the caveman.
    */
    void addCaveman(int maxAge, int minAge, int newIntelligence,
                    int newFitness, bool newIsMale);

    /**
     * Removes a caveman from the tribe.
     * @param id The id of the caveman to be removed.
     */
    void removeCaveman(short id);
    /**
     * Adds an Action to the actions vector
     */
    void addAction(std::unique_ptr<Action> newAction);
    /**
     * Erases an action from actions vector, typically because its finished
     * @param id The id of the action to be removed.
     */
    void removeAction(int id);
    /**
     * Returns a reference to the actions vector.
     */
    std::vector<std::unique_ptr<Action>>& getActions();

    void addEvent(std::shared_ptr<Event> newEvent);
    void removeEvent(short id);

    bool eventsAreEnabled();

    void enableEvents(bool enable = true);

    /**
     * Adds to Resources
     * @param amount Amount to be added to each resource.
     */
    void addToResources(Resources amount);
    /**
     * Returns false if the amount if resources-amount < 0
     * Also calls addToResources if true
     */
    bool checkAndAddResources(Resources amount);
    /**
     * Returns a reference to the tribe.
     */
    std::vector<std::shared_ptr<Caveman>>& getTribe();
    /**
     * Returns a reference to the techtree.
     */
    Techtree& getTechtree();
    /**
     * Returns a reference to the tribe.
     */
    Resources& getResources();
    /**
     * Returns current Tech Bonuses.
     */
    Tech::StatBoosts getTechBonuses();
    /**
     * Setter for Tech Bonuses, used in RoundEnd state.
     */
    void setTechBonuses(Tech::StatBoosts newTechBonuses);
    /**
     * Returns the current round number.
     */
    unsigned int getRoundNumber();
    /**
     * Increases the round number.
     * @param n Increment.
     */
    void increaseRoundNumber(unsigned int n = 1);
};

#endif
