#include "game.h"

#include "cavemanfactory.h"

void Game::repositionTribe() {
    int xPos = tribeXPos;
    for(auto& it : tribe){
        it->setPosition(TransformedVector<>(xPos, tribeYPos));
        xPos = xPos + 150;
    }
}

Game::Game() : techtree("assets/techtreebackground.png", "assets/tech/techtree.json", {1920, 1080}, 0) {
    CavemanFactory cavemanFactory;
    EventFactory eventFactory;

    // Starting population
    for(int i = 0; i < 3; ++i){
        tribe.push_back(cavemanFactory.createMale(5, 5));
    }
    for(int i = 0; i < 2; ++i){
        tribe.push_back(cavemanFactory.createFemale(5, 5));
    }

    repositionTribe();

    // starting resources
    resources.food = 200;
    resources.buildingMaterial = 50;
    resources.cavemanCapacity = 10;

    //events.push_back(eventFactory.createEvent(0, Narrative));
}

void Game::addCaveman(int maxAge, int minAge) {
    CavemanFactory cavemanFactory;
    tribe.push_back(cavemanFactory.createRandom(maxAge, minAge));

    repositionTribe();
}

void Game::removeCaveman(short id) {
    auto result = std::find_if(tribe.begin(), tribe.end(),
                               [&id](std::shared_ptr<Caveman> caveman) {
            return caveman->getId() == id;
    });

    if (result != std::end(tribe)) {
        tribe.erase(result);
    }

    repositionTribe();
}

std::vector<std::shared_ptr<Caveman>>& Game::getTribe() {
    return tribe;
}

void Game::addAction(std::shared_ptr<Action> newAction) {
    actions.push_back(std::move(newAction));
}

void Game::addEvent(std::shared_ptr<Event> newEvent) {
    events.push_back(std::move(newEvent));
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

void Game::removeEvent(short id) {
    for (int i = 0; i < events.size(); ++i) {
        if (events.at(i)->getID() == id) {
            events.at(i).reset();
            events.erase(events.begin() + i);
            return;
        }
    }
}

std::vector<std::shared_ptr<Action>>& Game::getActions() {
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

Tech::StatBoosts Game::getTechBonuses() {
    return techBonuses;
}

void Game::setTechBonuses(Tech::StatBoosts newTechBonuses) {
    techBonuses = newTechBonuses;
}

unsigned int Game::getRoundNumber(){
    return roundNumber;
}
void Game::increaseRoundNumber(unsigned int n){
    roundNumber += n;
}

