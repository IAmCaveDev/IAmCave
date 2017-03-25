#include "hunt.h"

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

        for (auto& it : actors) {
            totalFitness += it->getFitness();
        }

        float food = totalFitness * totalDuration;

        return{ true, food, 0, 0, false };
    }
}
