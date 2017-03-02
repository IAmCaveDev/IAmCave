#include "hunt.h"

Hunt::Hunt(EActions newtype, short time, Game& gameRef) : Action(time, gameRef){
    type = newtype;
}

void Hunt::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

void Hunt::resolve() {
    currentDuration += 1;
    if (currentDuration == totalDuration) {
        float newFood = 0;
        if (easy) {
            for (auto& it : actors) {
                newFood += it->getFitness() * 2;
                short fitness = it->getFitness();
                it->setFitness(fitness + totalDuration);
            }
        }
        else {
            for (auto& it : actors) {
                newFood += it->getFitness() * 4;
                short fitness = it->getFitness();
                it->setFitness(fitness + totalDuration*2);
            }
        }
        game.addToResources({newFood, 0, 0});
        for (auto& it : actors) {
            it->setCurrentAction(EActions::Idle);
        }
        game.removeAction(id);
    }
}