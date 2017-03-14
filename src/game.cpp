#include "game.h"

#include "cavemanfactory.h"

Game::Game(){
    CavemanFactory cavemanFactory;

    // Starting population
    for(int i = 0; i < 3; ++i){
        tribe.push_back(cavemanFactory.createMale(5, 5));
    }
    for(int i = 0; i < 2; ++i){
        tribe.push_back(cavemanFactory.createFemale(5, 5));
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

void Game::addCaveman(int maxAge, int minAge) {
    CavemanFactory cavemanFactory;
    tribe.push_back(cavemanFactory.createRandom(maxAge, minAge));
}

std::vector<std::shared_ptr<Caveman>>& Game::getTribe() {
    return tribe;
}

void Game::addAction(std::unique_ptr<Action> newAction) {
    actions.push_back(std::move(newAction));
}

void Game::removeAction(int id) {
    // TODO:write function properly
    for (int i = 0; i < actions.size(); ++i) {
        if (actions.at(i)->getID() == id) {
            actions.at(i).reset();
            actions.erase(actions.begin()+i);
            return;
        }
    }
}

std::vector<std::unique_ptr<Action>>& Game::getActions() {
    return actions;
}

void Game::addToResources(Resources amount) {
    resources.food += amount.food;
    resources.buildingMaterial += amount.buildingMaterial;
    resources.cavemanCapacity += amount.cavemanCapacity;
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

