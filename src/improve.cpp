#include "improve.h"

Improve::Improve(EActions newtype, short time) : Action(time){
    type = EActions::Improve;
}

void Improve::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

void Improve::resolve() {
    currentDuration += 1;

    if (currentDuration == totalDuration) {

        // Build process
        // Set cavemen to idle
        // Delete action
    }
}