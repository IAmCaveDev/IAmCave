#include "gamestate.h"

#include "game.h"

GameState::GameState(Game& gameRef) : game(gameRef) {}

GameState::~GameState() {
    for (auto& it : buttons) {
        delete it;
    }
    for (auto& it : rectangles) {
        delete it;
    }
}

void GameState::onResize(){
    for(auto& it : game.getTribe()){
        it->onResize();
    }
    for(auto& it : buttons){
        it->setPosition(it->getTransformedPosition());
        it->setSize(it->getTransformedSize());
    }
    for(auto& it : rectangles){
        it->setPosition(it->getTransformedPosition());
        it->setSize(it->getTransformedSize());
    }
}

std::vector<Button*>& GameState::getButtons(){
    return buttons;
}

std::vector<Rectangle*>& GameState::getRectangles() {
    return rectangles;
}

EGamestates GameState::getNextState(){
    return nextState;
}
void GameState::setNextState(EGamestates newNextState){
    nextState = newNextState;
}
