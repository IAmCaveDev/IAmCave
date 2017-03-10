#ifndef THINK_H
#define THINK_H

#include <vector>
#include <string>

#include "action.h"

class Think : public Action {
private:

public:
    Think(EActions newtype, short time);

    void addActor(Caveman* actor);
    short resolve();
};

#endif