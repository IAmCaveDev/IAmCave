#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <string>

// cyclic dependency otherwise
class Caveman;

enum EActions {
    Idle,
    EasyHunt,
    HardHunt,
    Sex,
    Think,
    Improve
};

class Action {
protected:
    std::vector<const Caveman*> actors;
    short totalDuration;
    short currentDuration;

public:
    Action() = delete;
    explicit Action(short time);

    virtual void addActor(Caveman* actor) = 0;
    virtual void resolve() = 0;
};

#endif
