#include "cavemanfactory.h"

std::unique_ptr<Caveman> CavemanFactory::createFemale(int maxAge, int minAge) {
    return std::unique_ptr<Female>(new Female(maxAge, minAge));
}

std::unique_ptr<Caveman> CavemanFactory::createMale(int maxAge, int minAge) {
    return std::unique_ptr<Male>(new Male(maxAge, minAge));
}
