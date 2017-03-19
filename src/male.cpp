#include "male.h"
#include "buttonfunctions.h"

#include <random>
#include <vector>

std::vector<std::string> maleNames = {
    "Donald",
    "Bernie",
    "Harambe",
    "Gabe",
    "Matthew",
    "Harry",
    "Ron",
    "Oswald",
    "Bruce"
};

std::vector<std::string> maleTextures = {
    "assets/caveman.png",
    "assets/caveman1.png",
    "assets/caveman2.png"
};

Male::Male(int maxAge, int minAge) : Caveman(maxAge, minAge) {
    std::random_device rd;
    std::mt19937 rng(rd());

    std::uniform_int_distribution<int> maleN(0, maleNames.size() - 1);
    name = maleNames[maleN(rng)];

    std::uniform_int_distribution<int> maleT(0, maleTextures.size() - 1);
    texPath = maleTextures[maleT(rng)];
}

bool Male::isMale() {
    return true;
}
