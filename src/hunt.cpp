#include "hunt.h"

Hunt::Hunt(EActions newtype, short time) : Action(time){
    type = newtype;
}

void Hunt::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

short Hunt::resolve() {
    currentDuration += 1;
    if (currentDuration == totalDuration) {
            short totalFitness = 0;
            short luck = (short)std::rand() % 10;

            for (auto& it : actors) {
                totalFitness += it->getFitness;
                if (it->isMale()) {
                    /** TODO
                    *   Add boni for male workers
                    */
                }
                it->setCurrentAction(EActions::Idle);
            }
            /** TODO
            *   Add gathering modifier
            */
            return totalFitness + luck * totalDuration * (easy * 2);
        }
        return 0;
}