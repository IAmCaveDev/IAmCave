#include "collect.h"

Collect::Collect(EActions newtype, short time) : Action(time){
    type = EActions::CollectAction;
}

void Collect::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

short Collect::resolve() {
    currentDuration += 1;
    if (currentDuration == totalDuration) {
        short totalFitness = 0;
        short luck = (short)std::rand() % 10;

        for (auto& it : actors) {
            totalFitness += it->getFitness();
            if (!it->isMale()) {
                /** TODO 
                *   Add boni for female workers
                */
            }
            it->setCurrentAction(EActions::Idle);
        }
        /** TODO
        *   Add gathering modifier
        */
        return totalFitness + luck * totalDuration;
    }

    return 0;
        //add resources
}
