#include "gamemanager.h"

GameManager::GameManager(std::string savePath, sf::RenderWindow& win)
                         : game(win),
                           mainMenu(game),
                           management(game),
                           roundEnd(game) {}

void GameManager::update() {
    EGamestates nextState = currentGameState->getNextState();

    if (nextState == EGamestates::mainMenu) {
        currentGameState->setNextState(EGamestates::mainMenu);
        currentGameState = &mainMenu;
    } else if (nextState == EGamestates::management) {
        currentGameState->setNextState(EGamestates::management);
        currentGameState = &management;
    } else if (nextState == EGamestates::roundEnd) {
        currentGameState->setNextState(EGamestates::roundEnd);
        currentGameState = &roundEnd;
    }
}
