#ifndef HUNT_H
#define HUNT_H

#include <vector>
#include <string>
#include "action.h"
#include "game.h"

class Hunt : public Action {
private:
    bool easy;
public:
    Hunt(EActions newtype, short duration, Game& gameRef);

    void addActor(Caveman* actor);
    void resolve();
};

#endif