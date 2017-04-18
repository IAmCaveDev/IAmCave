#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <string>
#include <memory>

#include "enum.h"
#include "caveman.h"


 /**
  * Used to return data from an Action's resolve function.
  *
  */
struct ActionPackage {
    /**
     * True if the action is finished and should be deleted.
     */
    bool isFinal;

    float food;
    int buildingMaterial;
    int cavemanCapacity;
    bool newborn;

    std::string techName;
};

/**
 * An action performed by one or more cavemen over one or more rounds.
 */

class Action {
private:
    /**
     * Counter for generating unique IDs.
     */
    static int counter;

protected:
    std::vector<std::shared_ptr<Caveman>> actors;
    short totalDuration;
    short currentDuration;
    EActions type;
    const int id;

public:
    Action() = delete;
    explicit Action(short time);

    /**
     * Returns the Action's ID.
     */
    const int getID();
    /**
    * Returns the Action's Type.
    */
    EActions getType();
    /**
    * Returns the Action's Duration.
    */
    short getDuration();
    /**
    * Returns the Action's Actors.
    */
    std::vector<std::shared_ptr<Caveman>>& getActors();
    /**
    * Adds a Caveman as an Actor to the Action.
    */
    virtual void addActor(std::shared_ptr<Caveman> actor) = 0;
    /**
     * Action logic.
     * Called every round in RoundEnd.
     * @return The changes caused by the Action.
     */
    virtual ActionPackage resolve() = 0;
};

#endif
