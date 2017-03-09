#ifndef CAVEMANFACTORY_H
#define CAVEMANFACTORY_H

#include <memory>

#include "caveman.h"
#include "female.h"
#include "male.h"

class CavemanFactory {
public:
    std::unique_ptr<Caveman> createFemale(int maxAge, int minAge);
    std::unique_ptr<Caveman> createMale(int maxAge, int minAge);

};
#endif