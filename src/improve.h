#ifndef IMPROVE_H
#define IMPROVE_H

#include <vector>
#include <string>
#include "action.h"

class Improve : public Action {
public:
    Improve(short time);

    void addActor(std::shared_ptr<Caveman> actor);
    ActionPackage resolve();
    ActionPackage resolve(Tech::StatBoosts bonuses);
};

#endif
