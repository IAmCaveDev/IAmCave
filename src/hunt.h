#ifndef HUNT_H
#define HUNT_H

#include <vector>
#include <string>
#include "action.h"

class Hunt : public Action {
private:
    bool isEasy;

public:
    Hunt(bool newIsEasy, short duration);

    void addActor(std::shared_ptr<Caveman> actor);
    ActionPackage resolve(Tech::StatBoosts bonuses);
};

#endif
