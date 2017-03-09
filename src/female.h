#ifndef FEMALE_H
#define FEMALE_H

#include <vector>
#include <string>

#include "caveman.h"

class Female : protected Caveman {
private:
    bool male = 0;
    short preg_counter = -1;
    bool pregnant = false;

public:
    Female(int maxAge, int minAge);

    bool isPregnant();

    void setPregnancy(bool newPregnant);
    
};


#endif