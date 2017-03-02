#include "action.h"

int Action::counter = 0;

Action::Action(short time, Game& gameRef) : totalDuration(time), game(gameRef), id(counter) {
    currentDuration = 0;
    counter += 1;
}

const int Action::getID() {
    return id;
}

EActions Action::getType() {
    return type;
}

