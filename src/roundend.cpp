#include "roundend.h"

#include "game.h"
#include <sstream>

void RoundEnd::resolveActions() {
    std::vector<int> toDelete = {};
    for (auto& it : game.getActions()) {

        ActionPackage result;
        if (it->getType() != EActions::ImproveAction ||
            (it->getType() == EActions::ImproveAction &&
             game.getResources().buildingMaterial - it->getActors().size() * 10 >= 0)) {
            result = it->resolve();
        } else {
            result = { false, 0.f, 2, 0, false };
        }

        if (!result.isFinal) {
            if (it->getType() == ImproveAction) {
                game.addToResources({ result.food,-result.buildingMaterial,result.cavemanCapacity });
            }
            return;
        } else {
            game.addToResources({ result.food,result.buildingMaterial,result.cavemanCapacity });
            if (result.newborn) {
                game.addCaveman(0, 0);
            }
            toDelete.push_back(it->getID());
        }
        for (auto& actor : it->getActors()) {
            if (actor->getCurrentAction() == Dead) game.removeCaveman(actor->getId());
        }
    }
    for (auto& it : toDelete) {
        game.removeAction(it);
    }
}

RoundEnd::RoundEnd(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::roundEnd;
    nextState = type;

    std::random_device rd;
    rng = std::mt19937(rd());

    infoColumn = new Textbox({450, 1080}, {0, 0}, "assets/endround-column.png",
                             "", 5, 30);
    textbox = new Textbox({1580, 140}, {20, 1080 - 160},
                          "assets/state-textbox.png", "", 15, 30);

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png"),
        infoColumn,
        textbox
    };

    buttons = {
        new Button({200, 80}, {-250, -130}, "assets/go.png", [&]() {
        nextState = EGamestates::management; })
    };
}

void RoundEnd::step(){
    Resources resourcesBefore = game.getResources();

    //resolve Actions
    resolveActions();

    // idle food consumption
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
    info << "Round " << game.getRoundNumber() << "\n"
         << "Food: " << resourcesBefore.food << " " << std::showpos
         << game.getResources().food - resourcesBefore.food
         << std::noshowpos << "\n"
         << "Building Material: " << resourcesBefore.buildingMaterial << " "
         << std::showpos << game.getResources().buildingMaterial
         - resourcesBefore.buildingMaterial << std::noshowpos << "\n"
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

void RoundEnd::setTextboxText(std::string str) {
    textbox->setText(str);
}

void RoundEnd::additionalResizes() {

}
