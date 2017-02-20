#include "management.h"
#include "rectangle.h"
#include "button.h"
#include "game.h"
#include "transformedvector.h"

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
        new Button({200, 50}, {200, 100}, "assets/hunt.png", hunt),
        new Button({50, 50}, {200, 400}, "assets/easyhunt.png", quit),
        new Button({50, 50}, {200, 400}, "assets/hardhunt.png", quit),
        new Button({200, 50}, {200, 200}, "assets/think.png", quit),
        new Button({200, 50}, {200, 300}, "assets/fuck.png", quit),
        new Button({200, 50}, {200, 400}, "assets/improve.png", quit),
        new Button({200, 50}, {-400, -100}, "assets/abort.png", abort)
    };

    buttons[2]->setVisibility(false);
    buttons[3]->setVisibility(false);
    buttons[7]->setVisibility(false);

}
