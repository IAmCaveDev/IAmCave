#ifndef CAVEMAN_H
#define CAVEMAN_H

#include <string>

#include "action.h"
#include "button.h"
#include "buttonfunctions.h"

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

    Button* button;

public:
    explicit Caveman(int maxAge, int minAge);
    ~Caveman();

    short getId();
    std::string getName();

    friend Action;
};

#endif
