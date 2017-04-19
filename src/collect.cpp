#include "collect.h"

Collect::Collect(short time) : Action(time) {
        type = EActions::CollectAction;
}

void Collect::addActor(std::shared_ptr<Caveman> newactor) {
    if(!newactor->isMale())
        actors.push_back(newactor);
}

ActionPackage Collect::resolve(Tech::StatBoosts bonuses) {
    currentDuration += 1;

    if (currentDuration == totalDuration) {
        short totalFitness = 0;

        for (auto& it : actors) {
            totalFitness += it->getFitness();
            it->setCurrentAction(Idle);
        }
        int materials = totalFitness * totalDuration + bonuses.addends.gatheringBonus;

        return{ true, 0.f, materials, 0, false };
    }

    return{ false, 0.f, 0, 0, false };
}
