#include "roundend.h"

#include "game.h"
#include <sstream>


RoundEnd::RoundEnd(std::vector<Caveman*>& newTribe, Resources& newResources)
                   : GameState(newTribe), resources(newResources) {
    std::random_device rd;
    rng = std::mt19937(rd());

    infoColumn = new Textbox({450, 1080}, {0, 0}, "assets/endround-column.png", "", 5, 30);

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png"),
        infoColumn,
    };

    buttons = {
        new Button({200, 50}, {-400, -150}, "assets/go.png",
                std::bind(&Game::setCurrentGameState, std::ref(gameRef), EGamestates::management))
    };
}

void RoundEnd::step(unsigned int roundNumber){
    Resources resourcesBefore = resources;

    //resolve Actions
    //for (auto& it : game.getActions()) {
    //   it->resolve();
    //}

    // food
    std::normal_distribution<float> normal(0, 0.33);

    for(auto& it : tribe){
        if((it->getCurrentAction() != EActions::EasyHunt) && (it->getCurrentAction() != EActions::HardHunt)){
            float foodConsumption = 1;

            if(it->getAge() > MIN_ADULT_AGE){
                foodConsumption += 1;

                if(it->isMale()){
                    foodConsumption += 1;
                }
                for(int i = 0; i < it->getFitness(); ++i){
                    foodConsumption += 0.05;
                }
            }

            foodConsumption += normal(rng);

            resources.food -= foodConsumption;
        }

    }
    if(resources.food < 0){
        resources.food = 0;
    }

    std::ostringstream info;
    info << "Round " << roundNumber << "\n"
         << "Food: " << resourcesBefore.food << " " << std::showpos
         << resources.food - resourcesBefore.food
         << std::noshowpos << "\n"
         << "Building Material: " << resourcesBefore.buildingMaterial << " "
         << std::showpos << resources.buildingMaterial
         - resourcesBefore.buildingMaterial << std::noshowpos << "\n"
         << "Cave Capacity: " << resourcesBefore.cavemanCapacity << " "
         << std::showpos << resources.cavemanCapacity
         - resourcesBefore.cavemanCapacity;

    infoColumn->setText(info.str());
}

void RoundEnd::display(sf::RenderWindow& win) {
    for (auto const& it : rectangles) {
        it->display(win);
    }

    for (auto const& it : buttons) {
        it->display(win);
    }
}
