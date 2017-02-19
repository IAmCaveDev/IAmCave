#ifndef CAVEMAN_H
#define CAVEMAN_H

#include <string>

#include "action.h"

class Caveman {
private:
    const short id;
    std::string name;

    const bool sex;
    unsigned short age;

    bool idle;

    short fitness;
    short intelligence;

public:
    Caveman();

    short getId();
    std::string getName();

    friend Action;
};

#endif
