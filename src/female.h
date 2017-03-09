#ifndef FEMALE_H
#define FEMALE_H

#include <vector>
#include <string>
#include "caveman.h"

class Female : protected Caveman {
private:
    bool male = 0;

public:
    Female(int maxAge, int minAge);
    void setPregnancy(bool newPregnant);
};


#endif