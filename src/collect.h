#ifndef COLLECT_H
#define COLLECT_H

#include <vector>
#include <string>

#include "action.h"
#include "game.h"

class Collect : public Action {
private:
    
public:
    Collect(EActions newtype, short duration);

    void addActor(Caveman* actor);
    void resolve();
};

#endif