#include "game.h"

Game::Game(sf::RenderWindow& windowRef) : window(windowRef),
                                          management(*this),
                                          roundEnd(*this){
}

void Game::update(){

}

const GameState& Game::getCurrentGameState() const {
    return *currentGameState;
}

bool Game::isActive() const {
    return active;
}

void Game::setActive(bool newActive){
    active = newActive;
}
