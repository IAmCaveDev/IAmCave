#include "think.h"

Think::Think(EActions newtype, short time) : Action(time){
    type = EActions::ThinkAction;
}

void Think::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

short Think::resolve() {
    /** TODO
    *   Implement tech tree and make use of it
    */
    return actors.size() * totalDuration;
}