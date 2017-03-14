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

    actionDisplay->addButton(0, new Button({200, 50}, {200, 300}, "assets/hunt-icon.png", nullptr), 1);
    actionDisplay->addButton(1, new Button({200, 50}, {200, 300}, "assets/makelove-icon.png", nullptr), 0);
    actionDisplay->addButton(2, new Button({200, 50}, {200, 300}, "assets/hunt-icon.png", nullptr), 2);
    actionDisplay->addButton(3, new Button({200, 50}, {200, 300}, "assets/hunt-icon.png", nullptr), 2);
    actionDisplay->removeButton(3);

    buttons = {
        new Button({200, 50}, {-400, -150}, "assets/go.png", [&](){
                    actionDisplay->decreasePriorityOfAll();
                    nextState = EGamestates::roundEnd;
                }),
        new Button({200, 50}, {200, 100}, "assets/hunt.png",
                std::bind(&ButtonFunctions::Managing::Hunting::hunt, std::ref(*this))),
        new Button({200, 50}, {200, 200}, "assets/think.png", nullptr),
        new Button({200, 50}, {200, 300}, "assets/makelove.png", nullptr),
        new Button({200, 50}, {200, 400}, "assets/improve.png", nullptr),
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
        //TODO: add more Actions here
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

std::vector<Caveman*> Management::getIdlingTribe() {
    std::vector<Caveman*> idlingTribe;
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
}
