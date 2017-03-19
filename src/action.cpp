#include "action.h"

int Action::counter = 0;

Action::Action(short time) : totalDuration(time), id(counter) {
    currentDuration = 0;
    counter += 1;
}

const int Action::getID() {
    return id;
}

EActions Action::getType() {
    return type;
}

short Action::getDuration() {
    return totalDuration;
}

std::vector<std::shared_ptr<Caveman>>& Action::getActors() {
    return actors;
}
