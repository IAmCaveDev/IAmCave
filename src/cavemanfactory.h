#ifndef CAVEMANFACTORY_H
#define CAVEMANFACTORY_H

#include <memory>

#include "caveman.h"

class CavemanFactory {
public:

    std::shared_ptr<Caveman> createRandom(int maxAge, int minAge);
    std::shared_ptr<Caveman> createMale(int maxAge, int minAge);
    std::shared_ptr<Caveman> createFemale(int maxAge, int minAge);
    std::shared_ptr<Caveman> createSpecific(int maxAge, int minAge, int newIntelligence, int newFitness, bool newIsMale);

};
#endif
