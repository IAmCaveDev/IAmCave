#include "think.h"

Think::Think(std::string techName, short time) : Action(time) {
    name = techName;
    type = EActions::ThinkAction;
}

void Think::addActor(std::shared_ptr<Caveman> newactor) {
    if (actors.size() < 1) {
        actors.push_back(newactor);
    }
}

ActionPackage Think::resolve() {
    currentDuration += 1;

    if (currentDuration == totalDuration) {
        actors.front()->setCurrentAction(Idle);
        return { true, 0, 0, 0, false, name };
    }

    return { false, 0, 0, 0, false };
}
