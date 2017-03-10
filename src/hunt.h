#ifndef HUNT_H
#define HUNT_H

#include <vector>
#include <string>

#include "action.h"

class Hunt : public Action {
private:
    bool easy;
public:
    Hunt(EActions newtype, short duration);

    void addActor(Caveman* actor);
    void resolve();
};

#endif