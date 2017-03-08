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
<<<<<<< HEAD
=======
private:
    static int counter;
>>>>>>> refs/remotes/origin/master

protected:

	Game& game;

    std::vector<Caveman*> actors;
<<<<<<< HEAD

    short totalDuration;	

    short currentDuration;	

=======
    short totalDuration;
    short currentDuration;
    EActions type;
    const int id;
>>>>>>> refs/remotes/origin/master

public:
    Action() = delete;
    explicit Action(short time);

    const int getID();
    EActions getType();
    virtual void addActor(Caveman* actor) = 0;
    virtual void resolve() = 0;
};

#endif
