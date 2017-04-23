#include "gamemanager.h"

GameManager::GameManager(std::string savePath, sf::RenderWindow& win)
                         : window(win),
                           mainMenu(game),
                           management(game),
                           roundEnd(game),
                           winScreen(game),
                           loseScreen(game) {
    if (savePath.empty()) {
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
            currentGameState->setNextState(currentState);
            currentGameState = &mainMenu;
        } else if (nextState == EGamestates::management) {
            currentGameState->setNextState(currentState);
            currentGameState = &management;
            management.resetTextbox();
        } else if (nextState == EGamestates::roundEnd) {
            currentGameState->setNextState(currentState);
            currentGameState = &roundEnd;
            roundEnd.step();
        } else if (nextState == EGamestates::winScreen) {
            currentGameState->setNextState(currentState);
            currentGameState = &winScreen;
            management.resetTextbox();
        } else if (nextState == EGamestates::loseScreen) {
            currentGameState->setNextState(currentState);
            currentGameState = &loseScreen;
            management.resetTextbox();
        } else if (nextState == EGamestates::quit) {
            window.close();
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
