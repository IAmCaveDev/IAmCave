#include "actionfactory.h"

std::shared_ptr<Action> ActionFactory::createEasyHuntingAction(short duration) {
    return std::unique_ptr<Hunt> (new Hunt(true, duration));
}

std::shared_ptr<Action> ActionFactory::createHardHuntingAction(short duration) {
    return std::unique_ptr<Hunt>(new Hunt(false, duration));
}

std::shared_ptr<Action> ActionFactory::createCollectAction(short duration) {
    return std::unique_ptr<Collect>(new Collect(duration));
}

std::shared_ptr<Action> ActionFactory::createSexAction() {
    return std::unique_ptr<Sex>(new Sex());
}

std::shared_ptr<Action> ActionFactory::createImproveAction(short duration) {
    return std::unique_ptr<Improve>(new Improve(duration));
}

std::shared_ptr<Action> ActionFactory::createThinkingAction(std::string techName,short duration) {
    return std::unique_ptr<Think>(new Think(techName, duration));
}
