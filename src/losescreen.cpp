#include "losescreen.h"

LoseScreen::LoseScreen(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::loseScreen;
    nextState = type;

    rectangles = {
        new Rectangle({ 1920, 1080 },{ 0, 0 }, "assets/lose.png")
    };

    buttons = {
        new Button({ 200, 80 },{ 200, 100 }, "assets/play.png", [&]() {
        //gameref.reset() ? 
        nextState = EGamestates::management;
    }),
        new Button({ 300, 255 },{ 685, 830 }, "assets/menu-exit.png", [&]() {
        nextState = EGamestates::quit;
    })
    };
}

void LoseScreen::display(sf::RenderWindow& win) {
    for (auto const& it : rectangles) {
        it->display(win);
    }
    for (auto const& it : buttons) {
        it->display(win);
    }
}

void LoseScreen::additionalResizes() {

}