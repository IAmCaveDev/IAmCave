#ifndef IMPROVE_H
#define IMPROVE_H

#include <vector>
#include <string>
#include "action.h"

class Improve : public Action {
private:

public:
    Improve(short time, Resources cost);

    void addActor(std::shared_ptr<Caveman> newActor);
    ActionPackage resolve(Tech::StatBoosts bonuses);

};

#endif
