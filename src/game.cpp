#include "game.h"

Game::Game(sf::RenderWindow& windowRef) : window(windowRef),
                                          management(*this),
                                          //roundEnd(*this),
                                          mainMenu(*this){
    setCurrentGameState(EGamestates::mainMenu);

    for(int i = 0; i < 5; ++i){
        addCaveman(5,5);
    }

    int xPos = 500;
    int yPos = 500;
    for(auto& it : tribe){
        it->setPosition(TransformedVector<>(xPos, yPos));
        xPos = xPos + 150;
        if (xPos >= 1080) {
            xPos = 500;
            yPos = yPos + 250;
        }
    }
}

void Game::display(){
    currentGameState->display(window);
}

void Game::addCaveman(int maxAge, int minAge) {
    tribe.push_back(new Caveman(maxAge, minAge));
}

std::vector<Caveman*>& Game::getTribe() {
    return tribe;
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
       /* case EGamestates::roundEnd:
            currentGameState = &roundEnd;
            break;*/
    }
    currentGameState->onResize();
}

sf::RenderWindow& Game::getWindow() {
    return window;
}

