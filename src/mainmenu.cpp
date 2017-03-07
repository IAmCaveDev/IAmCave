#include "mainmenu.h"
#include "button.h"
#include "game.h"
#include "buttonfunctions.h"

MainMenu::MainMenu(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::mainMenu;

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/background.png")
    };

    buttons = {
        new Button({200, 50}, {200, 100}, "assets/play.png", [&](){
                    nextState = EGamestates::management;
                }),
        new Button({200, 50}, {200, 200}, "assets/options.png",
                   ButtonFunctions::MainMenu::options),
        new Button({200, 50}, {200, 300}, "assets/exit.png", [&](){
                    nextState = EGamestates::quit;
                })
    };

}

void MainMenu::display(sf::RenderWindow& win) {
    for (auto const& it : rectangles) {
        it->display(win);
    }
    for (auto const& it : buttons) {
        it->display(win);
    }
}
