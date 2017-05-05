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
                } else if (name == "revolution") {
                    nextState = EGamestates::winScreen;
                    return;
                } else {
                    tech = game.getTechtree().getTree()
                        .find(name)
                        ->second;
                    game.getTechtree().setTrainingMode(false);
                }
                game.setTechBonuses(game.getTechBonuses() + tech->getBonuses());
                it->getActors().front()->addIntelligence(tech->getIntelligenceGain());
                tech->setResearched(true);
            }

        } else {
            game.addToResources({ result.food,
                                  result.buildingMaterial,
                                  result.cavemanCapacity });
            if (result.newborn) {
                int numberOfMales = 0;
                for (auto& it : game.getTribe()) {
                    if (it->isMale()) numberOfMales++;
                }
                if (numberOfMales <= 1) {
                    game.addCaveman(0, 0, -1, -1, true);
                } else if (game.getTribe().size() - numberOfMales <= 1) {
                    game.addCaveman(0, 0, -1, -1, false);
                } else {
                    game.addCaveman(0, 0);
                }
                tribeChanges++;
            }
        }

        if (result.isFinal) {
            toDelete.push_back(it->getID());

            for (auto& actor : it->getActors()) {
                if (actor->getCurrentAction() == Dead) {
                    game.removeCaveman(actor->getId());
                    tribeChanges--;
                }
            }
        }
    }
    for (auto& it : toDelete) {
        game.removeAction(it);
    }
}

void RoundEnd::doPassives() {
    std::vector<int> toDelete = {};

    // idle food consumption
    std::normal_distribution<float> normal(0, 0.33);

    for (auto& it : game.getTribe()) {
        if (it->getCurrentAction() != EActions::EasyHunt &&
            it->getCurrentAction() != EActions::HardHunt) {
            float foodConsumption = 0;

            if (it->getAge() > MIN_ADULT_AGE) {
                foodConsumption += 5;
                //commented out temporary for balancing
                /*if (it->isMale()) {
                    foodConsumption += 1;
                }*/
                for (int i = 0; i < it->getFitness(); ++i) {
                    foodConsumption += 0.1;
                }
            }
            
            foodConsumption += normal(rng);
            
            if (foodConsumption > game.getResources().food) {
                it->setFitness(it->getFitness() - 1);
            }

            game.getResources().food -= foodConsumption;
        }

    }
    //aging & death when fitness = 0
    for (auto& it : game.getTribe()) {
        it->aging();
        if (it->getAge() >= 50) {
            it->setFitness(it->getFitness() - 5);
        }
        if (it->getFitness() == 0) {
            it->setCurrentAction(EActions::Dead);
            toDelete.push_back(it->getId());
        }
    }
    //passive intelligence gain
    for (auto& it : game.getTribe()) {
        it->addIntelligence(game.getTechBonuses().addends.passiveIntGain);
    }

    for (auto& it : toDelete) {
        game.removeCaveman(it);
        tribeChanges--;
    }
}

void RoundEnd::doEvents(Resources resourcesBefore) {
    EventFactory eventFactory;
    std::random_device rd;
    std::mt19937 rng(rd());

    if (!distribution(rng)) {
        std::shared_ptr<Event> event(eventFactory.createRandomEvent());
        //TODO make sure ALL trigger requirements are met
        if (resourcesBefore.food >= event->getTrigger().tribeFood
            || resourcesBefore.buildingMaterial >= event->getTrigger().tribeMaterial
            || resourcesBefore.cavemanCapacity >= event->getTrigger().tribeSize
            || game.getTechtree().getTree().at(event->getTrigger().has_tech)->isResearched()
            || !game.getTechtree().getTree().at(event->getTrigger().missing_tech)) {

            for (auto& it : event->getOptions()) {
                if (it == event->getOptions().at(0)) {
                    buttons.at(0)->changeTexture(it->texturePath);
                    buttons.at(0)->setCallback(std::bind(&ButtonFunctions::Events::confirmOption, std::ref(*this), it, event->getID()));
                    buttons.at(0)->setPosition(it->button->getPosition());
                } else {
                    it->button->setCallback(std::bind(&ButtonFunctions::Events::confirmOption, std::ref(*this), it, event->getID()));
                    buttons.push_back(it->button);
                }
            }
            setTextboxText(event->getDescription());
            game.addEvent(event);
        }
    }
}

RoundEnd::RoundEnd(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::roundEnd;
    nextState = type;

    std::random_device rd;
    rng = std::mt19937(rd());
    tribeChanges = 0;

    textbox = new Textbox({ 1580, 160 }, { 20, 1080 - 180 },
                          "assets/state-textbox.png", "", 15, 30);

    cavemanBox = new Textbox({247, 350}, {205, 470},
                             "assets/roundendbox.png", "moo", 5, 30,
                             {215, 190, 152});

    foodBox = new Textbox({247, 350}, {516, 470},
                          "assets/roundendbox.png", "moo", 5, 30,
                          {215, 190, 152});

    materialBox = new Textbox({247, 350}, {995, 470},
                              "assets/roundendbox.png", "moo", 5, 30,
                              {215, 190, 152});

    capacityBox = new Textbox({247, 350}, {1536, 470},
                              "assets/roundendbox.png", "moo", 5, 30,
                              {215, 190, 152});

    roundBox = new Textbox({540, 175}, {820, 35}, "assets/roundbox.png", "moo",
                           5, 60, {215, 190, 152});

    rectangles = {
        new Rectangle({ 1920, 1080 }, { 0, 0 }, "assets/roundend.png"),
        textbox,
        cavemanBox,
        foodBox,
        materialBox,
        capacityBox,
        roundBox
    };

    buttons = {
        new Button({ 200, 80 }, { -250, -130 }, "assets/go.png", [&]() {
            nextState = EGamestates::management; })
    };
}

void RoundEnd::step() {
    Resources resourcesBefore = game.getResources();
    tribeChanges = 0;
    int tribeBefore = game.getTribe().size();

    doPassives();

    resolveActions();

    if (game.eventsAreEnabled()) {
        doEvents(resourcesBefore);
    }

    if (game.getResources().food < 0) {
        game.getResources().food = 0;
    }
    if (game.getResources().buildingMaterial < 0) {
        game.getResources().buildingMaterial = 0;
    }

    //game over when reaching round 100 without revolution
    if (game.getRoundNumber() == 100) {
        nextState = EGamestates::loseScreen;
        return;
    }

    game.increaseRoundNumber();
    std::ostringstream tribeInfo;
    tribeInfo << tribeBefore << " " << std::showpos
        << tribeChanges;
    std::ostringstream foodInfo;
    foodInfo << resourcesBefore.food << " " << std::showpos
             << game.getResources().food - resourcesBefore.food;

    std::ostringstream materialInfo;
    materialInfo << resourcesBefore.buildingMaterial << " "
         << std::showpos << game.getResources().buildingMaterial
         - resourcesBefore.buildingMaterial;

    std::ostringstream capacityInfo;
    capacityInfo << resourcesBefore.cavemanCapacity << " "
         << std::showpos << game.getResources().cavemanCapacity
         - resourcesBefore.cavemanCapacity;

    cavemanBox->setText(tribeInfo.str());
    foodBox->setText(foodInfo.str());
    materialBox->setText(materialInfo.str());
    capacityBox->setText(capacityInfo.str());

    roundBox->setText("Round " + std::to_string(game.getRoundNumber()-1));
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
