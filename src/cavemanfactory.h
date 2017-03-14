#ifndef CAVEMANFACTORY_H
#define CAVEMANFACTORY_H

#include <memory>

#include "caveman.h"
//#include "male.h"
//#include "female.h"

class CavemanFactory {
public:

    std::unique_ptr<Caveman> createRandom();
    std::unique_ptr<Caveman> createMale();
    std::unique_ptr<Caveman> createFemale();

};
#endif