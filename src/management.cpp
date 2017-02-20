#include "management.h"
#include "rectangle.h"
#include "button.h"
#include "game.h"
#include "transformedvector.h"

Management::Management(Game& gameRef) : GameState(gameRef) {

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/cave.png")
    };

    std::function<void()> start = [&]() {
        game.setCurrentGameState(EGamestates::management);
    };

    std::function<void()> options = []() {

    };

    std::function<void()> quit = [&]() {
        game.getWindow().close();
    };

    buttons = {
        new Button({200, 50}, {-400, -150}, "assets/go.png", start),
        new Button({200, 50}, {200, 100}, "assets/hunt.png", options),
        new Button({200, 50}, {200, 200}, "assets/think.png", quit),
        new Button({200, 50}, {200, 300}, "assets/fuck.png", quit),
        new Button({200, 50}, {200, 400}, "assets/improve.png", quit)
    };


}
