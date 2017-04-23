#ifndef IMPROVE_H
#define IMPROVE_H

#include <vector>
#include <string>
#include "action.h"

class Improve : public Action {
private:
    int materialCosts = 10;

public:
    Improve(short time);

    void addActor(std::shared_ptr<Caveman> newActor);
    ActionPackage resolve(Tech::StatBoosts bonuses);

    int getMaterialCosts();
};

#endif
