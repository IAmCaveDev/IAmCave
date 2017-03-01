#include "game.h"

Game::Game(sf::RenderWindow& windowRef) : window(windowRef),
                                          management(*this),
                                          roundEnd(*this),
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

    // starting resources
    resources.food = 200;
    resources.buildingMaterial = 50;
    resources.cavemanCapacity = 10;
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

void Game::addActiontoQueue(Action* newaction) {
    queuedActions.push_back(newaction);
}

GameState& Game::getCurrentGameState(){
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
            roundEnd.step();
            currentGameState = &roundEnd;
            break;
    }
    currentGameState->onResize();
}

Resources& Game::getResources(){
    return resources;
}

unsigned int Game::getRoundNumber(){
    return roundNumber;
}
void Game::increaseRoundNumber(unsigned int n){
    roundNumber += n;
}

sf::RenderWindow& Game::getWindow() {
    return window;
}

