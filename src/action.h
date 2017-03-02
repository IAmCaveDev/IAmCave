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

//Test Description
class Action {

protected:

	Game& game;

	//List of cavemen assigned to this action
    std::vector<Caveman*> actors;

	//Amount of turns for which this action is locked
    short totalDuration;	

	//Turns taken already
    short currentDuration;	


public:
    Action() = delete;
    explicit Action(short time, Game& gameRef);

    virtual void addActor(Caveman* actor) = 0;
    virtual void resolve() = 0;
};

#endif
