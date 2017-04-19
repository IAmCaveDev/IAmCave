#include "sex.h"

Sex::Sex() : Action(3) {
    type = EActions::SexAction;
}

void Sex::addActor(std::shared_ptr<Caveman> newactor) {
    if(!newactor->isMale()) {
        //Check if static_cast is needed
        if((std::dynamic_pointer_cast<Female>)(newactor)->isPregnant())
            return;
    }

    if(actors.empty())
        actors.push_back(newactor);
    else if(actors.size() < 2 && actors.front()->isMale() != newactor->isMale())
        actors.push_back(newactor);
}

ActionPackage Sex::resolve(Tech::StatBoosts bonuses) {
    currentDuration += 1;

    for (auto& it : actors) {
        //Possible bug source if male is not removed from actors
        if (it->isMale()) {
            it->setCurrentAction(Idle);
        }
        else if (!it->isMale()) {
            (std::dynamic_pointer_cast<Female>)(it)->setPregnant(true);
        }
    }
    if (currentDuration == totalDuration) {
        for (auto& it : actors) {
            if (!it->isMale()) {
                it->setCurrentAction(EActions::Idle);
            }
        }
        return{ true, 0, 0, 0, true };
    }
    return{ false, 0, 0, 0, false };
}
