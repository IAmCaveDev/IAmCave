#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <string>

// cyclic dependency otherwise
class Caveman;
class Game;

enum EActions {
    Idle,
    EasyHunt,
    HardHunt,
    Sex,
    Think,
    Improve
};

class Action {
private:
    static int counter;

protected:
    std::vector<Caveman*> actors;
    short totalDuration;
    short currentDuration;
    Game& game;
    EActions type;
    const int id;

public:
    Action() = delete;
    explicit Action(short time, Game& gameRef);

    const int getID();
    EActions getType();
    virtual void addActor(Caveman* actor) = 0;
    virtual void resolve() = 0;
};

#endif
