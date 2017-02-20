#ifndef CAVEMAN_H
#define CAVEMAN_H

#include <string>

#include "action.h"
#include "button.h"

class Caveman {
private:
    static short counter;

    const short id;
    std::string name;

    bool male;
    unsigned short age;

    bool idle;

    short fitness;
    short intelligence;

public:
    explicit Caveman(int maxAge = 50, int minAge = 0);

    short getId();
    std::string getName();

    friend Action;
};

#endif
