#ifndef CAVEMANFACTORY_H
#define CAVEMANFACTORY_H

#include <memory>

#include "caveman.h"

class CavemanFactory {
public:

    std::unique_ptr<Caveman> createRandom(int maxAge, int minAge);
    std::unique_ptr<Caveman> createMale(int maxAge, int minAge);
    std::unique_ptr<Caveman> createFemale(int maxAge, int minAge);

};
#endif
