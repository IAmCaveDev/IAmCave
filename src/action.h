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
    CollectAction,
    SexAction,
    ThinkAction,
    ImproveAction
};

class Action {
private:
    static int counter;

protected:
    std::vector<Caveman*> actors;
    short totalDuration;
    short currentDuration;
    EActions type;
    const int id;

public:
    Action() = delete;
    explicit Action(short time);

    const int getID();
    EActions getType();
    virtual void addActor(Caveman* actor) = 0;
    virtual short resolve() = 0;
};

#endif