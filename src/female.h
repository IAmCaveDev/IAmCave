#ifndef FEMALE_H
#define FEMALE_H

#include "caveman.h"

/**
 * A female Caveman.
 */
class Female : public Caveman {
private:
    bool pregnant;

    Female(int maxAge, int minAge);

public:
    /**
     * @return false
     */
    bool isMale();
    bool isPregnant();
    void setPregnant(bool preggo);

    friend class CavemanFactory;
};

#endif

