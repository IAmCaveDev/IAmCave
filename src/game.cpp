#include "game.h"

Game::Game(sf::RenderWindow& windowRef) : window(windowRef),
                                          management(*this),
                                          roundEnd(*this),
                                          mainMenu(*this){}

void Game::update(){
    for (auto const& it : currentGameState->getRectangles()) {
        it->display(window);
    }

    for (auto const& it : currentGameState->getButtons()) {
        it->display(window);
    }
}

void Game::addCaveman(int maxAge, int minAge) {
    tribe.push_back(new Caveman(maxAge, minAge));
}

GameState& Game::getCurrentGameState() const {
    return *currentGameState;
}

void Game::setCurrentGameState(EGamestates newstate) {
    switch (newstate) {
        case EGamestates::mainMenu:
            currentGameState = &mainMenu;
            break;
        case EGamestates::management:
            currentGameState = &management;
            break;
        case EGamestates::roundEnd:
            currentGameState = &roundEnd;
            break;
    }
    currentGameState->onResize();
}

sf::RenderWindow& Game::getWindow() {
    return window;
}

