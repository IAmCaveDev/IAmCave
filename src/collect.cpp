#include "collect.h"

#include <random>

Collect::Collect(short time) : Action(time) {
        type = EActions::CollectAction;
}

void Collect::addActor(std::shared_ptr<Caveman> newactor) {
    if(!newactor->isMale())
        actors.push_back(newactor);
}

ActionPackage Collect::resolve(Tech::StatBoosts bonuses) {
    currentDuration += 1;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, 50);

    if (currentDuration == totalDuration) {
        float totalFitness = 0;

        for (auto& it : actors) {
            int deathChance = distribution(rng);

            if (deathChance == 10) {
                it->setCurrentAction(EActions::Dead);
            } else {
                totalFitness += it->getFitness();
                if (it->getAge() < 50) {
                    it->setFitness(it->getFitness() + 1 + bonuses.addends.fitnessGain);
                }
                it->setCurrentAction(Idle);
            }
        }
        int materials = totalFitness * totalDuration + bonuses.addends.gatheringBonus;

        return{ true, 0.f, materials, 0, false };
    }

    return{ false, 0.f, 0, 0, false };
}
