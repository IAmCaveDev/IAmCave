#ifndef MALE_H
#define MALE_H

#include "caveman.h"

/**
 * A male Caveman.
 */
class Male : public Caveman {
private:
    Male(int maxAge, int minAge);

public:
    /**
     * @return true
     */
    bool isMale();

    friend class CavemanFactory;
};

#endif
