#ifndef MALE_H
#define MALE_H

#include <vector>
#include <string>

#include "caveman.h"

class Male : protected Caveman {
private:
    bool male = 1;

public:
    Male(int maxAge, int minAge);
};


#endif