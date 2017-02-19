#include "gamestate.h"

GameState::GameState(Game& gameRef) : game(gameRef){
}

std::vector<Button*>& GameState::getButtons(){
    return buttons;
}
