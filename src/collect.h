#ifndef COLLECT_H
#define COLLECT_H

#include <vector>
#include <string>

#include "action.h"
#include "game.h"   /** TODO Avoid this */

class Collect : public Action {
private:
    
public:
    Collect(EActions newtype, short duration);

    void addActor(Caveman* actor);
    short resolve();
};

#endif