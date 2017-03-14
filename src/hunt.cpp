#include "hunt.h"

Hunt::Hunt(EActions newtype, short time) : Action(time){
    type = EActions::EasyHunt;
}

void Hunt::addActor(std::shared_ptr<Caveman> newactor) {
    actors.push_back(newactor);
}

void Hunt::resolve() {
    currentDuration += 1;
    if (currentDuration == totalDuration) {
        //add resources
        //set cavemen to idle
        //delete action
    }
}
