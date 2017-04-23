#include "improve.h"

#include <cmath>

Improve::Improve(short time, Resources cost) : Action(time, cost) {
    type = EActions::ImproveAction;
}

void Improve::addActor(std::shared_ptr<Caveman> newActor) {
    actors.push_back(newActor);
    totalDuration = 10 * std::pow(0.5f, actors.size() - 1.f);
}

ActionPackage Improve::resolve(Tech::StatBoosts bonuses) {
    currentDuration += 1;

    if (currentDuration >= totalDuration) {
        for (auto& it : actors) {
            it->setCurrentAction(Idle);
        }
        return{ true, 0.f, 0, 1, false };
    }
    return{ false, 0.f, 0, 0, false };
}


