#include "hunt.h"

#include <random>

Hunt::Hunt(bool newIsEasy, short time) : Action(time) {
    isEasy = newIsEasy;
    if (isEasy) {
        type = EActions::EasyHunt;
    } else {
        type = EActions::HardHunt;
    }
}

void Hunt::addActor(std::shared_ptr<Caveman> newactor) {
    actors.push_back(newactor);
}

ActionPackage Hunt::resolve(Tech::StatBoosts bonuses) {
    currentDuration += 1;

    if (currentDuration == totalDuration) {
        float totalFitness = 0;
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> distribEasy(0, 20);
        std::uniform_int_distribution<int> distribHard(0, 10);

        int pos = 0;
        for (auto& it : actors) {
            int casualtyDice;
            if (isEasy) {
                casualtyDice = distribEasy(rng);
            } else {
                casualtyDice = distribHard(rng);
            }

            if (!casualtyDice) {
                it->setCurrentAction(Dead);
            } else {
                totalFitness += it->getFitness();
                if (isEasy) {
                    it->setFitness(it->getFitness() + 1 + bonuses.addends.fitnessGain);
                } else {
                    it->setFitness(it->getFitness() + 2 + bonuses.addends.fitnessGain);
                }
                it->setCurrentAction(Idle);
            }

            pos++;
        }

        float food = 20 + totalFitness * totalDuration + bonuses.addends.huntBonus;

        return { true, food, 0, 0, false };
    }

    return { false, 0.f, 0, 0, false };
}
