#include "roundend.h"

#include "game.h"
#include <sstream>


RoundEnd::RoundEnd(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::roundEnd;
    nextState = type;

    std::random_device rd;
    rng = std::mt19937(rd());

    infoColumn = new Textbox({450, 1080}, {0, 0}, "assets/endround-column.png", "", 5, 30);

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png"),
        infoColumn,
    };

    buttons = {
        new Button({200, 80}, {-400, -120}, "assets/go.png", [&]() {
        nextState = EGamestates::management; })
    };
}

void RoundEnd::step(){
    Resources resourcesBefore = game.getResources();

    //resolve Actions
    //for (auto& it : game.getActions()) {
    //   it->resolve();
    //}

    // food
    std::normal_distribution<float> normal(0, 0.33);

    for(auto& it : game.getTribe()){
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

            game.getResources().food -= foodConsumption;
        }

    }
    if(game.getResources().food < 0){
        game.getResources().food = 0;
    }

    std::ostringstream info;
    info << "Round " << game.getRoundNumber() << "\n\n"
         << "Food: " << round(resourcesBefore.food) << " " << std::showpos
         << round(game.getResources().food - resourcesBefore.food)
         << std::noshowpos << "\n\n"
         << "Building Material: " << round(resourcesBefore.buildingMaterial) << " "
         << std::showpos << round(game.getResources().buildingMaterial
         - resourcesBefore.buildingMaterial) << std::noshowpos << "\n\n"
         << "Cave Capacity: " << resourcesBefore.cavemanCapacity << " "
         << std::showpos << game.getResources().cavemanCapacity
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
