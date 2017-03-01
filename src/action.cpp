#include "action.h"

Action::Action(short time, Game& gameRef) : totalDuration(time), game(gameRef) {
    currentDuration = 0;
}

