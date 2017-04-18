#include "female.h"
#include "buttonfunctions.h"

#include <random>
#include <vector>

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

Female::Female(int maxAge, int minAge) : Caveman(maxAge, minAge) {
    std::random_device rd;
    std::mt19937 rng(rd());

    std::uniform_int_distribution<int> femaleName(0, femaleNames.size() - 1);
    name = femaleNames[femaleName(rng)];

    std::uniform_int_distribution<int> femaleTex(1, 162);
    texPath = "assets/women/woman-" + std::to_string(femaleTex(rng)) + ".png";

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
