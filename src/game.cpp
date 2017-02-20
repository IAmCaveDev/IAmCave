#include "game.h"

Game::Game(sf::RenderWindow& windowRef) : window(windowRef),
                                          management(*this),
                                          roundEnd(*this),
                                          mainMenu(*this){}

void Game::update(){
    for (auto const& it : currentGameState->getRectangles()) {
        window.draw(*it);
    }

    for (auto const& it : currentGameState->getButtons()) {
        window.draw(*it);
    }
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
}

sf::RenderWindow& Game::getWindow() {
    return window;
}

