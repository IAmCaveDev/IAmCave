#include "management.h"

#include "rectangle.h"
#include "verticalbuttonlist.h"
#include "button.h"
#include "game.h"
#include "transformedvector.h"
#include "buttonfunctions.h"

Management::Management(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::management;
    nextState = type;

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png"),
    };

    actionFactory = ActionFactory();

    actionDisplay = new VerticalButtonList({50, 1080}, {-50, 0}, "");

    buttons = {
        new Button({200, 80}, {-250, -130}, "assets/go.png", [&](){
                    actionDisplay->decreasePriorityOfAll();
                    nextState = EGamestates::roundEnd;
                }),
        new Button({200, 80}, {50, 50}, "assets/hunt.png",
                std::bind(&ButtonFunctions::Managing::Hunting::hunt, std::ref(*this))),
        new Button({200, 80}, {50, 150}, "assets/think.png",
                std::bind(&ButtonFunctions::Managing::Research::think, std::ref(*this), std::ref(gameRef.getTechtree()))),
        new Button({200, 80}, {50, 250}, "assets/makelove.png", nullptr),
        new Button({200, 80}, {50, 350}, "assets/improve.png", nullptr),
    };

}

void Management::setCurrentAction(EActions newaction, short duration) {
    switch (newaction) {
        case EActions::EasyHunt:
            currentAction = std::move(actionFactory.createEasyHuntingAction(duration));
            break;
        case EActions::HardHunt:
            currentAction = std::move(actionFactory.createHardHuntingAction(duration));
            break;
        // TODO: add more Actions here
    }

}

Action& Management::getCurrentAction() {
    return *currentAction;
}

void Management::pushCurrentAction() {
    EActions currentType = currentAction->getType();

    switch (currentType) {
        case EActions::EasyHunt:
            actionDisplay->addButton(currentAction->getID(), new Button({ 200, 50 }, { 200, 300 },
                                    "assets/hunt-icon.png", nullptr), currentAction->getDuration());
            break;
        case EActions::HardHunt:
            actionDisplay->addButton(currentAction->getID(), new Button({ 200, 50 }, { 200, 300 },
                                    "assets/hunt-icon.png", nullptr), currentAction->getDuration());
            break;
        case EActions::Sex:
            actionDisplay->addButton(currentAction->getID(), new Button({ 200, 50 }, { 200, 300 },
                                    "assets/makelove-icon.png", nullptr), currentAction->getDuration());
            break;
        case EActions::Improve:
            actionDisplay->addButton(currentAction->getID(), new Button({ 200, 50 }, { 200, 300 },
                                    "assets/improve-icon.png", nullptr), currentAction->getDuration());
            break;
        case EActions::Think:
            actionDisplay->addButton(currentAction->getID(), new Button({ 200, 50 }, { 200, 300 },
                                    "assets/think-icon.png", nullptr), currentAction->getDuration());
            break;
    }

    for (auto& it : currentAction->getActors()) {
        it->setCurrentAction(currentType);
    }

    game.addAction(std::move(currentAction));
}

void Management::deleteCurrentAction() {
    currentAction.reset();
}

void Management::setActiveTech(std::string newTech) {
    activeTech = newTech;
    int i = 0;
}

std::string Management::getActiveTech() {
    return activeTech;
}

std::vector<std::shared_ptr<Caveman>> Management::getIdlingTribe() {
    std::vector<std::shared_ptr<Caveman>> idlingTribe;
    for (auto& it : game.getTribe()) {
        if (it->getCurrentAction() == EActions::Idle) {
            idlingTribe.push_back(it);
        }
    }
    return idlingTribe;
}

VerticalButtonList& Management::getActionDisplay() {
    return *actionDisplay;
}

void Management::display(sf::RenderWindow& win) {
    for (auto const& it : rectangles) {
        it->display(win);
    }

    for (auto const& it : buttons) {
        it->display(win);
    }

    actionDisplay->display(win);

    for (auto const& it : getIdlingTribe()) {
        it->display(win);
    }

    game.getTechtree().display(win);

}
