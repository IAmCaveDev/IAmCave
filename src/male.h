#ifndef MALE_H
#define MALE_H

#include "caveman.h"

class Male : public Caveman {
private:
    Male(int maxAge, int minAge);

public:
    bool isMale();

    friend class CavemanFactory;
};

#endif
