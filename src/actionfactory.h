#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include <memory>
#include <string>

#include "action.h"
#include "hunt.h"
#include "collect.h"
#include "improve.h"
#include "sex.h"
#include "think.h"

class ActionFactory {
public:
    std::unique_ptr<Action> createEasyHuntingAction(short duration);
    std::unique_ptr<Action> createHardHuntingAction(short duration);
    std::unique_ptr<Action> createCollectAction(short duration);
    std::unique_ptr<Action> createSexAction();
    std::unique_ptr<Action> createImproveAction(short duration);
    std::unique_ptr<Action> createThinkingAction(std::string techName, short duration);
    //TODO: more methods for creating other actions

};
#endif
