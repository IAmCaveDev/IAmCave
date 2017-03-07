#include "game.h"

Game::Game(){
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

void Game::addCaveman(int maxAge, int minAge) {
    tribe.push_back(new Caveman(maxAge, minAge));
}

std::vector<Caveman*>& Game::getTribe() {
    return tribe;
}

void Game::addAction(Action* newaction) {
    actions.push_back(newaction);
    switch (newaction->getType()) {
        case (EActions::EasyHunt): ;
            // management.getActionDisplay().addButton(newaction->getID(), new Button({ 200, 50 }, { 200, 300 }, "assets/hunt-icon.png", nullptr), 0);
        //TODO: more cases with different icons
    }
}

void Game::removeAction(int id) {
    // management.getActionDisplay().removeButton(id);
    //TODO:write function properly
    for (int i = 0; i < actions.size(); ++i) {
        if (actions.at(i)->getID() == id) {
            delete actions.at(i);
            actions.erase(actions.begin() + i);
        }
    }
}

std::vector<Action*> Game::getActions() {
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

