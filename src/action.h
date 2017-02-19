#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <string>

// cyclic dependency otherwise
class Caveman;

class Action {
private:
    std::vector<const Caveman*> actors;
    short duration;

public:
    Action();

};

#endif
