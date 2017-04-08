#include "game.h"

#include "cavemanfactory.h"

Game::Game() : techtree("assets/tech/techtree.json", {1920, 1080}, 0) {
    CavemanFactory cavemanFactory;
    EventFactory eventFactory;

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

    eventStack.push_back(eventFactory.createEvent(0, Narrative));
}

void Game::addCaveman(int maxAge, int minAge) {
    CavemanFactory cavemanFactory;
    tribe.push_back(cavemanFactory.createRandom(maxAge, minAge));
}

void Game::removeCaveman(short id) {
    //TODO implement
}

std::vector<std::shared_ptr<Caveman>>& Game::getTribe() {
    return tribe;
}

void Game::addAction(std::unique_ptr<Action> newAction) {
    actions.push_back(std::move(newAction));
}

void Game::removeAction(int id) {
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

Techtree& Game::getTechtree(){
    return techtree;
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

