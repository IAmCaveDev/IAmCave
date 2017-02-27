#include "roundend.h"

#include "game.h"
#include <sstream>


RoundEnd::RoundEnd(Game& gameRef) : GameState(gameRef) {
    std::random_device rd;
    rng = std::mt19937(rd());

    beforeColumn = new Textbox({300, 1080}, {0, 0}, "assets/endround-column.png", "", 5, 30);
    afterColumn = new Textbox({300, 1080}, {300, 0}, "assets/endround-column.png", "", 5, 30);

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png"),
        beforeColumn,
        afterColumn
    };

    buttons = {
        new Button({200, 50}, {-400, -150}, "assets/go.png",
                std::bind(&Game::setCurrentGameState, std::ref(gameRef), EGamestates::management))
    };
}

void RoundEnd::step(){
    std::ostringstream infoBefore;
    infoBefore << "Before\n"
               << "Food: " << game.getResources().food << "\n"
               << "Building Material: " << game.getResources().buildingMaterial
               << "\n"
               << "Cave Capacity: " << game.getResources().cavemanCapacity;

    // food
    std::normal_distribution<float> normal(0, 0.33);

    for(auto& it : game.getTribe()){
        if(it->getCurrentAction() != EActions::Hunting){
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

    std::ostringstream infoAfter;
    infoAfter << "After\n"
              << "Food: " << game.getResources().food << "\n"
              << "Building Material: " << game.getResources().buildingMaterial
              << "\n"
              << "Cave Capacity: " << game.getResources().cavemanCapacity;

    beforeColumn->setText(infoBefore.str());
    afterColumn->setText(infoAfter.str());
}

void RoundEnd::display(sf::RenderWindow& win) {
    for (auto const& it : rectangles) {
        it->display(win);
    }

    for (auto const& it : buttons) {
        it->display(win);
    }
}
