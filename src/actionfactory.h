#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include <memory>

#include "action.h"
#include "hunt.h"
#include "sex.h"
#include "improve.h"
#include "think.h"
#include "collect.h"

class ActionFactory {
public:
    std::unique_ptr<Action> createEasyHuntingAction(short duration);
    std::unique_ptr<Action> createHardHuntingAction(short duration);
    std::unique_ptr<Action> createSexAction(short duration);
    std::unique_ptr<Action> createImproveAction(short duration);
    std::unique_ptr<Action> createThinkAction(short duration);
    std::unique_ptr<Action> createCollectAction(short duration);

};
#endif