#ifndef CAVEMANFACTORY_H
#define CAVEMANFACTORY_H

#include <memory>

#include "caveman.h"

/**
* A Factory class for creating Caveman objects.
*/
class CavemanFactory {
public:

    std::shared_ptr<Caveman> createRandom(int maxAge, int minAge);
    std::shared_ptr<Caveman> createMale(int maxAge, int minAge);
    std::shared_ptr<Caveman> createFemale(int maxAge, int minAge);

};
#endif
