#include "female.h"
#include "buttonfunctions.h"

#include <random>

std::vector<std::string> femaleNames = {
    "Hillary",
    "Liz",
    "Gina",
    "Chelsea",
    "Luna",
    "Giny",
    "Selina",
    "Lillian",
    "Harleen"
};

std::vector<std::string> femaleTextures = {
    "assets/cavewoman.png",
    "assets/cavewoman2.png",
    "assets/cavewoman3.png"
};

Female::Female(int maxAge, int minAge) : Caveman(maxAge, minAge) {
    std::random_device rd;
    std::mt19937 rng(rd());

    std::uniform_int_distribution<int> femaleN(0, femaleNames.size() - 1);
    name = femaleNames[femaleN(rng)];

    std::uniform_int_distribution<int> femaleT(0, femaleTextures.size() - 1);
    texPath = femaleTextures[femaleT(rng)];

    button = new Button({ 100, 200 }, { 0, 0 }, texPath, nullptr,
        std::bind(&ButtonFunctions::Tribe::displayInfo,
            std::shared_ptr<Caveman>(this)));

}

bool Female::isMale() {
    return false;
}

bool Female::isPregnant() {
    return pregnant;
}

void Female::setPregnant(bool preggo) {
    pregnant = preggo;
}