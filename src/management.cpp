#include "management.h"
#include "rectangle.h"
#include "button.h"
#include "game.h"
#include "transformedvector.h"
#include "buttonfunctions.h"

Management::Management(Game& gameRef) : GameState(gameRef) {

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png")
    };

    std::function<void()> go = [&]() {
        //every action -1 time and execute all actions with time=0
        game.setCurrentGameState(EGamestates::roundEnd);
    };

    std::function<void()> hunt = [&]() {
        //display 2 additional buttons; select one; select cavemen; create new Hunting action

    };

    std::function<void()> quit = [&]() {
        game.getWindow().close();
    };

    buttons = {
        new Button({200, 50}, {-400, -150}, "assets/go.png", go),
        new Button({200, 50}, {200, 100}, "assets/hunt.png",
                   std::bind(&ButtonFunctions::Managing::Hunting::hunt, std::ref(*this))),
        new Button({200, 50}, {200, 200}, "assets/think.png", quit),
        new Button({200, 50}, {200, 300}, "assets/fuck.png", quit),
        new Button({200, 50}, {200, 400}, "assets/improve.png", quit),
        new Button({200, 50}, {-400, -50}, "assets/abort.png", nullptr)
    };

}

void Management::display(sf::RenderWindow& win) {
    for (auto const& it : rectangles) {
        it->display(win);
    }

    int xPos = 500;
    int yPos = 800;
    for (auto const& it : game.getTribe()) {
        // it->getButton().setPosition(TransformedVector<> (xPos, yPos));
        it->display(win);
        xPos = xPos + 100;
        if (xPos == 1000) {
            xPos = 400;
            yPos = yPos + 200;
        }
    }

    for (auto const& it : buttons) {
        it->display(win);
    }
}
