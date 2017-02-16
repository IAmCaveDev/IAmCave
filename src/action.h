#ifndef ACTION_H
#define ACTION_H

#include <string>

#include "caveman.h"

class Action {
private:
    std::vector<const Caveman*> actors;
    short duration;

public:
    Action();

};

#endif
