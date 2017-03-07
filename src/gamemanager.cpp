#include "gamemanager.h"

GameManager::GameManager(std::string savePath, sf::RenderWindow& win)
                         : window(win),
                           mainMenu(game),
                           management(game),
                           roundEnd(game) {
    if (savePath.compare("")) {
        currentGameState = &mainMenu;
    } else {
        currentGameState = &management;
    }
}

void GameManager::display(){
    currentGameState->display(window);
}

void GameManager::update() {
    EGamestates currentState = currentGameState->getType();
    EGamestates nextState = currentGameState->getNextState();

    if(nextState != currentState){
        if (nextState == EGamestates::mainMenu) {
            currentGameState->setNextState(EGamestates::mainMenu);
            currentGameState = &mainMenu;
        } else if (nextState == EGamestates::management) {
            currentGameState->setNextState(EGamestates::management);
            currentGameState = &management;
        } else if (nextState == EGamestates::roundEnd) {
            currentGameState->setNextState(EGamestates::roundEnd);
            currentGameState = &roundEnd;
        } else if (nextState == EGamestates::quit) {

        }
        currentGameState->onResize();
    }
}

Game& GameManager::getGame() {
    return game;
}

GameState& GameManager::getCurrentGameState() {
    return *currentGameState;
}

sf::RenderWindow& GameManager::getWindow() {
    return window;
}
