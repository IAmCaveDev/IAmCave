#include "gamemanager.h"

GameManager::GameManager(std::string savePath, sf::RenderWindow& win)
                         : window(win),
                           mainMenu(game),
                           management(game),
                           roundEnd(game) {
    if (savePath.empty()) {
        currentGameState = &mainMenu;
    } else {
        currentGameState = &management;
    }

    roundEnd.setTextboxText("Lorem ipsum dolor sit amet, consetetur\
sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore\
et dolore magna aliquyam erat, sed diam voluptua. At vero eos et\
accusam et justo duo dolores et ea rebum. Stet clita kasd\
gubergren, no sea takimata sanctus est Lorem ipsum dolor sit\
amet.");
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
