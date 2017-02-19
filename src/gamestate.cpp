#include "gamestate.h"

GameState::GameState(Game& gameRef) : game(gameRef){
    
}

GameState::~GameState() {
    for (auto& it : buttons) {
        delete it;
    }
    for (auto& it : drawables) {
        delete it;
    }
}

std::vector<Button*>& GameState::getButtons(){
    return buttons;
}

std::vector<sf::Drawable*>& GameState::getDrawables() {
    return drawables;
}
