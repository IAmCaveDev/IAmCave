#include "game.h"

#include "cavemanfactory.h"

void Game::repositionTribe() {
    int totalTribeWidth = (normalCavemanWidth + tribePadding) * tribe.size() -
                          tribePadding;
    int availableTribeWidth = 1920 - tribeLeftPadding - tribeRightPadding;

    if (totalTribeWidth >= availableTribeWidth) {
        tribeScale = static_cast<float>(availableTribeWidth) /
                     static_cast<float>(totalTribeWidth);
    } else {
        tribeScale = 1;
    }

    int xPos = tribeLeftPadding;
    for(auto& it : tribe){
        int translationDueToSize = normalCavemanHeight - normalCavemanHeight *
                                   tribeScale;

        it->setPosition(TransformedVector<>(xPos, tribeYPos + translationDueToSize));
        it->setSize({static_cast<int>(normalCavemanWidth * tribeScale),
                     static_cast<int>(normalCavemanHeight * tribeScale)});
        xPos += (normalCavemanWidth + tribePadding) * tribeScale;
    }
}

Game::Game() : techtree("assets/background-techtree.png",
                        "assets/tech/techtree.json", {1920, 1080}, 0,
                        100, 280, 100) {

    CavemanFactory cavemanFactory;
    EventFactory eventFactory;

    // Starting population
    for(int i = 0; i < 10; ++i){
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

    eventStack.push_back(eventFactory.createEvent(0, Narrative));
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

