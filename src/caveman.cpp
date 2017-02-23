#include "caveman.h"

#include <random>
#include <vector>

short Caveman::counter = 0;

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

std::vector<std::string> femaleTextures = {
    "assets/cavewoman.png",
    "assets/cavewoman2.png",
    "assets/cavewoman3.png"
};

std::vector<std::string> maleTextures = {
    "assets/caveman.png",
    "assets/caveman2.png",
    "assets/caveman3.png"
};

Caveman::Caveman(int maxAge, int minAge) : id(counter){
    idle = true;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> unid(minAge, maxAge);

    age = unid(rng);


    std::uniform_int_distribution<int> unbd(0, 1);

    if(counter < 3){
        male = true;
    }else if(counter < 5){
        male = false;
    }else{
        male = (unbd(rng) != 0);
    }

    std::uniform_int_distribution<int> maleD(0, maleNames.size() - 1);
    std::uniform_int_distribution<int> femaleD(0, femaleNames.size() - 1);

    if(male){
        name = maleNames[maleD(rng)];
    }else{
        name = femaleNames[femaleD(rng)];
    }


    std::uniform_int_distribution<int> stats(1, 5);

    fitness = stats(rng);
    intelligence = stats(rng);

    std::string texture;
    std::uniform_int_distribution<int> maleT(0, femaleTextures.size() - 1);
    std::uniform_int_distribution<int> femaleT(0, maleTextures.size() - 1);

    if (male) {
        texture = maleTextures[maleT(rng)];
    }else{
        texture = femaleTextures[femaleT(rng)];
    }

    button = new Button({ 200, 50 }, { 200, 100 }, texture,
        nullptr, std::bind(&ButtonFunctions::Tribe::displayInfo, std::ref(*this)));

    counter += 1;
}

Caveman::~Caveman() {
    delete button;
}