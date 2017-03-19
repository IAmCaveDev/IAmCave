#ifndef FEMALE_H
#define FEMALE_H

#include "caveman.h"

class Female : public Caveman {
private:
    bool pregnant;

    Female(int maxAge, int minAge);

public:
    bool isMale();
    bool isPregnant();
    void setPregnant(bool preggo);

    friend class CavemanFactory;
};

#endif

