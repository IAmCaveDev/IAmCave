#ifndef HUNT_H
#define HUNT_H

#include <vector>
#include <string>
#include "action.h"

class Hunt : public Action {
private:
    bool isEasy;

public:
    Hunt(EActions newtype, short duration);

    void addActor(std::shared_ptr<Caveman> actor);
    void resolve();
};

#endif
