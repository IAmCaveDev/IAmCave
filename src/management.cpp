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

	resources = new resourceDisplay(gamereference);
	rectangles = {
		new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png"),
		new Rectangle({ 200, 400 },{ 1223, 160 }, "assets/heaps/meat-l.png"),
		new Rectangle({ 400, 800 },{ 1400, 138 }, "assets/heaps/stones-m.png"),
		new Textbox({ 450, 150 },{ 800, 0 }, "assets/resource-column.png", "Beds: " + std::to_string(gameRef.getResources().cavemanCapacity), 5, 30),
		new Textbox({ 450, 150 },{ 400, 0 }, "assets/resource-column.png", "Meat: " + std::to_string(int(gameRef.getResources().food)), 5, 30),
		new Textbox({ 450, 150 },{ 600, 0 }, "assets/resource-column.png", "Stones: " + std::to_string(gameRef.getResources().buildingMaterial), 5, 30),
		new Rectangle({ 2160, 70 },{ 0, 900 }, "assets/cave-grass.png")
    };

    actionFactory = ActionFactory();

    actionDisplay = new VerticalButtonList({50, 1080}, {-50, 0}, "");

    actionDisplay->addButton(0, new Button({200, 80}, {200, 300}, "assets/hunt-icon.png", nullptr), 1);
    actionDisplay->addButton(1, new Button({200, 80}, {200, 300}, "assets/makelove-icon.png", nullptr), 0);
    actionDisplay->addButton(2, new Button({200, 80}, {200, 300}, "assets/hunt-icon.png", nullptr), 2);
    actionDisplay->addButton(3, new Button({200, 80}, {200, 300}, "assets/hunt-icon.png", nullptr), 2);
    actionDisplay->removeButton(3);

    buttons = {
        new Button({200, 80}, {-400, -150}, "assets/go.png", [&](){
                    nextState = EGamestates::roundEnd;
                }),
        new Button({200, 80}, {200, 100}, "assets/hunt.png",
                std::bind(&ButtonFunctions::Managing::Hunting::hunt, std::ref(*this))),
        new Button({200, 80}, {200, 200}, "assets/think.png", nullptr),
        new Button({200, 80}, {200, 300}, "assets/makelove.png", nullptr),
        new Button({200, 80}, {200, 400}, "assets/improve.png", nullptr),
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
        // add more Actions here
    }

}

Action& Management::getCurrentAction() {
    return *currentAction;
}

void Management::pushCurrentAction() {
    game.addAction(std::move(currentAction));
    //deleteCurrentAction();
    // TODO: set currentAction in all caveman who are participating from idle
    // to EActions::Actiontype
}

void Management::deleteCurrentAction() {
    currentAction = nullptr;
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

	

	for (auto const& it : game.getTribe()) {
		it->display(win);
	}


	//resources->getGrassTexture().display(win);


	rectangles[1] = resources->getHeaps()[0];
	rectangles[2] = resources->getHeaps()[1];
	rectangles[3] = resources->getResources()[0];
	rectangles[4] = resources->getResources()[1];
	rectangles[5] = resources->getResources()[2];
	rectangles[6]->display(win);

	/*
	sf::Texture textureMeat = resources->getFoodTexture();
	rectangles[1]->setTexture(&textureMeat);

	sf::Texture textureMaterials = resources->getMaterialsTexture();
	rectangles[2]->setTexture(&textureMaterials);
	*/
}
