#include "actionfactory.h"

std::unique_ptr<Action> ActionFactory::createEasyHuntingAction(short duration) {
    return std::unique_ptr<Hunt> (new Hunt(EActions::EasyHunt , duration));
}

std::unique_ptr<Action> ActionFactory::createHardHuntingAction(short duration) {
    return std::unique_ptr<Hunt>(new Hunt(EActions::HardHunt, duration));
}

std::unique_ptr<Action> createSexAction(short duration) {
    return std::unique_ptr<Sex>(new Sex(EActions::Sex, duration));
}

std::unique_ptr<Action> createImproveAction(short duration) {
    return std::unique_ptr<Improve>(new Improve(EActions::Improve, duration));
}

std::unique_ptr<Action> createThinkAction(short duration) {
    return std::unique_ptr<Thinks>(new Think(EActions::Think, duration));
}

std::unique_ptr<Action> createCollectAction(short duration) {
    return std::unique_ptr<Collect>(new Collect(EActions::Collect, duration));
}