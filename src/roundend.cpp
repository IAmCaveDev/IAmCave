#include "roundend.h"

#include <sstream>
#include <algorithm>

#include "game.h"
#include "buttonfunctions.h"

void RoundEnd::resolveActions() {
    std::vector<int> toDelete = {};
    for (auto& it : game.getActions()) {

        ActionPackage result = it->resolve(game.getTechBonuses());

        if (it->getType() == EActions::ThinkAction) {
            if (result.isFinal) {
                std::string name = result.techName;
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                std::shared_ptr<Tech> tech;
                if (name == "training") {
                    tech = game.getTechtree().getTraining();
                }
                else {
                    tech = game.getTechtree().getTree()
                        .find(name)
                        ->second;
                }
                game.setTechBonuses(game.getTechBonuses() + tech->getBonuses());
                it->getActors().front()->addIntelligence(tech->getIntelligenceGain());
                tech->setResearched(true);
            }

        }
        else {
            Tech::StatBoosts bonuses = game.getTechBonuses();
            if (it->getType() == EActions::EasyHunt ||
                it->getType() == EActions::HardHunt) {
                result.food += bonuses.addends.huntBonus;
            }
            else if (it->getType() == EActions::CollectAction) {
                result.food += bonuses.addends.gatheringBonus;
            }
            game.addToResources({ result.food,
                result.buildingMaterial,
                result.cavemanCapacity });
            if (result.newborn) {
                game.addCaveman(0, 0);
            }
        }

        if (result.isFinal) {
            toDelete.push_back(it->getID());

            for (auto& actor : it->getActors()) {
                if (actor->getCurrentAction() == Dead) game.removeCaveman(actor->getId());
            }
        }
    }
    for (auto& it : toDelete) {
        game.removeAction(it);
    }
}

void RoundEnd::doPassives() {
    // idle food consumption
    std::normal_distribution<float> normal(0, 0.33);

    for (auto& it : game.getTribe()) {
        if (it->getCurrentAction() != EActions::EasyHunt &&
            it->getCurrentAction() != EActions::HardHunt) {
            float foodConsumption = 1;

            if (it->getAge() > MIN_ADULT_AGE) {
                foodConsumption += 1;

                if (it->isMale()) {
                    foodConsumption += 1;
                }
                for (int i = 0; i < it->getFitness(); ++i) {
                    foodConsumption += 0.05;
                }
            }

            foodConsumption += normal(rng);

            game.getResources().food -= foodConsumption;
        }

    }
}

void RoundEnd::doEvents(Resources resourcesBefore) {
    EventFactory eventFactory;
    std::shared_ptr<Event> event(eventFactory.createRandomEvent());
    //TODO make sure ALL trigger requirements are met
    if (resourcesBefore.food >= event->getTrigger().tribeFood
        || resourcesBefore.buildingMaterial >= event->getTrigger().tribeMaterial
        || resourcesBefore.cavemanCapacity >= event->getTrigger().tribeSize) {
        rectangles.push_back(event->getTextBox());
        for (auto& it : event->getOptions()) {
            Button* button = new Button({ 200, 100 }, { 850, 700 }, "assets/confirm.png", 
                std::bind(&ButtonFunctions::Events::confirmOption, std::ref(game), it->effects, event->getID())
                , nullptr);

            buttons.push_back(button);
        }
    }
    game.addEvent(event);
}

RoundEnd::RoundEnd(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::roundEnd;
    nextState = type;

    std::random_device rd;
    rng = std::mt19937(rd());

    infoColumn = new Textbox({ 450, 1080 }, { 0, 0 }, "assets/endround-column.png",
        "", 5, 30);
    textbox = new Textbox({ 1580, 160 }, { 20, 1080 - 180 },
        "assets/state-textbox.png", "", 15, 30);

    rectangles = {
        new Rectangle({ 1920, 1080 },{ 0, 0 }, "assets/cave.png"),
        infoColumn,
        textbox
    };

    buttons = {
        new Button({ 200, 80 },{ -250, -130 }, "assets/go.png", [&]() {
        nextState = EGamestates::management; })
    };
}

void RoundEnd::step() {
    Resources resourcesBefore = game.getResources();

    resolveActions();

    doPassives();

    doEvents(resourcesBefore);

    if (game.getResources().food < 0) {
        game.getResources().food = 0;
    }
    if (game.getResources().buildingMaterial < 0) {
        game.getResources().buildingMaterial = 0;
    }

    game.increaseRoundNumber();

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