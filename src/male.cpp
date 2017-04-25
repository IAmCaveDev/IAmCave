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

Male::Male(int maxAge, int minAge) : Caveman(maxAge, minAge) {
    std::random_device rd;
    std::mt19937 rng(rd());

    std::uniform_int_distribution<int> maleName(0, maleNames.size() - 1);
    name = maleNames[maleName(rng)];

    std::uniform_int_distribution<int> maleTex(1, 702);
    texPath = "assets/men/man-" + std::to_string(maleTex(rng)) + ".png";
}

bool Male::isMale() {
    return true;
}
