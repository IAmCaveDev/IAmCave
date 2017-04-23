#include "cavemanfactory.h"

#include <random>

#include "male.h"
#include "female.h"

std::shared_ptr<Caveman> CavemanFactory::createRandom(int maxAge, int minAge) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> dis(0, 1);

    if (dis(rng) == 0) {
        std::shared_ptr<Male> male(new Male(maxAge, minAge));
        male->initButton();
        return male;
    } else {
        std::shared_ptr<Female> female(new Female(maxAge, minAge));
        female->initButton();
        return female;
    }
}

std::shared_ptr<Caveman> CavemanFactory::createMale(int maxAge, int minAge) {
    std::shared_ptr<Male> male(new Male(maxAge, minAge));
    male->initButton();
    return male;
}

std::shared_ptr<Caveman> CavemanFactory::createFemale(int maxAge, int minAge) {
    std::shared_ptr<Female> female(new Female(maxAge, minAge));
    female->initButton();
    return female;
}

std::shared_ptr<Caveman> CavemanFactory::createSpecific(int maxAge, int minAge, int newIntelligence, int newFitness, bool newIsMale) {
    if (newIsMale) {
        std::shared_ptr<Male> male(new Male(maxAge, minAge));
        male->setFitness(newFitness);
        male->setIntelligence(newFitness);
        male->initButton();
        return male;
    } else {
        std::shared_ptr<Female> female(new Female(maxAge, minAge));
        female->setFitness(newFitness);
        female->setIntelligence(newFitness);
        female->initButton();
        return female;
    }
}
