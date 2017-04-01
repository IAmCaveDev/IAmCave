#include "hunt.h"

#include <random>

Hunt::Hunt(bool newIsEasy, short time) : Action(time) {
    isEasy = newIsEasy;
    if (isEasy) {
        type = EActions::EasyHunt;
    }
    else {
        type = EActions::HardHunt;
    }
}

void Hunt::addActor(std::shared_ptr<Caveman> newactor) {
    actors.push_back(newactor);
}

ActionPackage Hunt::resolve() {
    currentDuration += 1;


    if (currentDuration == totalDuration) {
        short totalFitness = 0;
        short num_casualties = 0;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1, 20);
        auto casualtyDice = std::bind(distribution, generator);
        int pos = 0;

        for (auto& it : actors) {
            //std::random_device rd;
            //std::mt19937 rng(rd());

            if (!casualtyDice()) {
                actors.erase(actors.begin() + pos);
                it->~Caveman();
            }
            totalFitness += it->getFitness();
			it->setCurrentAction(Idle);
            pos++;
        }

        float food = totalFitness * totalDuration;

        return{ true, food, 0, 0, false };
    }

	return{ false, 0.f, 0, 0, false };
}
