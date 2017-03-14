#include "cavemanfactory.h"

#include <random>

#include "male.h"
#include "female.h"

std::unique_ptr<Caveman> CavemanFactory::createRandom(int maxAge, int minAge) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> dis(0, 1);

    if (dis(rng) == 0) {
        return std::unique_ptr<Male>(new Male(maxAge, minAge));
    } else {
        return std::unique_ptr<Female>(new Female(maxAge, minAge));
    }
}

std::unique_ptr<Caveman> CavemanFactory::createMale(int maxAge, int minAge) {
    return std::unique_ptr<Male>(new Male(maxAge, minAge));
}

std::unique_ptr<Caveman> CavemanFactory::createFemale(int maxAge, int minAge) {
    return std::unique_ptr<Female>(new Female(maxAge, minAge));
}
