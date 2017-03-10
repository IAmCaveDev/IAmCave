#include "improve.h"

Improve::Improve(EActions newtype, short time) : Action(time){
    type = EActions::ImproveAction;
}

void Improve::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

short Improve::resolve() {
    currentDuration += 1;

    if (currentDuration == totalDuration) {

        return actors.size() * totalDuration;
        // Build process
        // Set cavemen to idle
        // Delete action
    }
}