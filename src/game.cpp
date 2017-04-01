#include "game.h"

Game::Game(){
    for(int i = 0; i < 5; ++i){
        addCaveman(5,5);
    }

    int xPos = 200;
    int yPos = 750;
    for(auto& it : tribe){
        it->setPosition(TransformedVector<>(xPos, yPos));
        xPos = xPos + 150;

		if (xPos >= 1920){
			xPos = 325;
		}
		/*

        if (xPos >= 1920) {
            xPos = 500;
            yPos = yPos + 250;
        }

		*/
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

void Game::addAction(std::unique_ptr<Action> newAction) {
    switch (newAction->getType()) {
        case (EActions::EasyHunt) : ;
            //TODO: handle actionqueue
    }
    actions.push_back(std::move(newAction));
}

void Game::removeAction(int id) {
    //TODO:write function properly
    //remove icon from actionDisplay
    //delete action from actions vector
    //delete unique_ptr action object
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

