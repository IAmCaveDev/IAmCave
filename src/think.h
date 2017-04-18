#ifndef THINK_H
#define THINK_H

#include <vector>
#include <string>

#include "action.h"
#include "tech.h"

class Think : public Action {
private:
    std::string name;

public:
    Think(std::string techName, short time);

    void addActor(std::shared_ptr<Caveman> actor);
    ActionPackage resolve();
};

#endif
