#include "gamestate.h"

GameState::GameState(Game& gameRef) : game(gameRef){
}

const std::vector<Button>& GameState::getButtons() const {
    return buttons;
}
