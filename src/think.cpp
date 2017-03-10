#include "think.h"

Think::Think(EActions newtype, short time) : Action(time){
    type = EActions::Think;
}

void Think::addActor(Caveman* newactor) {
    actors.push_back(newactor);
}

void Think::resolve() {
    /** TODO
    *   Implement tech tree and make use of it
    */
}