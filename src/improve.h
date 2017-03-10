#ifndef IMPROVE_H
#define IMPROVE_H

#include <vector>
#include <string>

#include "action.h"

class Improve : public Action {
private:

public:
    Improve(EActions newtype, short duration);

    void addActor(Caveman* actor);
    short resolve();
};

#endif