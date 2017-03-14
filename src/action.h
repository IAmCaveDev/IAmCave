#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <string>
#include <memory>

#include "enum.h"
#include "caveman.h"

class Action {
private:
    static int counter;

protected:
    std::vector<std::shared_ptr<Caveman>> actors;
    short totalDuration;
    short currentDuration;
    EActions type;
    const int id;

public:
    Action() = delete;
    explicit Action(short time);

    const int getID();
    EActions getType();
    short getDuration();
    std::vector<std::shared_ptr<Caveman>>& getActors();
    virtual void addActor(std::shared_ptr<Caveman> actor) = 0;
    virtual void resolve() = 0;
};

#endif
