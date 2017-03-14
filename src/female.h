#ifndef FEMALE_H
#define FEMALE_H

#include "caveman.h"

class Female : public Caveman {
private:
    bool pregnant;
public:
    Female(int maxAge, int minAge);
    bool isMale();
    bool isPregnant();
    void setPregnant(bool preggo);
};

#endif

