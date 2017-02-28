#include "hunt.h"

Hunt::Hunt(bool diff, short time) : Action(time){
    easy = diff;
}

void Hunt::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

void Hunt::resolve() {
    currentDuration = currentDuration + 1;
    if (currentDuration == totalDuration) {
        //do hunt stuff +food +death chance
    }
}