#include "gamestate.h"

GameState::GameState(Game& gameRef) : game(gameRef){}

GameState::~GameState() {
    for (auto& it : buttons) {
        delete it;
    }
    for (auto& it : rectangles) {
        delete it;
    }
}

std::vector<Button*>& GameState::getButtons(){
    return buttons;
}

std::vector<Rectangle*>& GameState::getRectangles() {
    return rectangles;
}
