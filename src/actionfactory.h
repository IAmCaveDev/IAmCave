#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include <memory>

#include "action.h"
#include "hunt.h"

class ActionFactory {
public:

    std::unique_ptr<Action> createEasyHuntingAction(short duration);
    std::unique_ptr<Action> createHardHuntingAction(short duration);
    //TODO: more methods for creating other actions

};
#endif