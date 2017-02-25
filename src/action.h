#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <string>

// cyclic dependency otherwise
class Caveman;

class Action {
protected:
    std::vector<const Caveman*> actors;
    short duration;

public:
    Action() = delete;
    explicit Action(short time);

    virtual void addActor(Caveman* actor) = 0;
};

#endif
