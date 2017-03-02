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

protected:

	Game& game;

    std::vector<Caveman*> actors;

    short totalDuration;	

    short currentDuration;	


public:
    Action() = delete;
    explicit Action(short time, Game& gameRef);

    virtual void addActor(Caveman* actor) = 0;
    virtual void resolve() = 0;
};

#endif
