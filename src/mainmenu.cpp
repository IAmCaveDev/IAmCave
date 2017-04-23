#include "mainmenu.h"
#include "button.h"
#include "game.h"

MainMenu::MainMenu(Game& gameRef) : GameState(gameRef) {
    type = EGamestates::mainMenu;
    nextState = type;

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/background.png")
    };

    buttons = {
        new Button({845, 635}, {800, 180}, "assets/menu-start.png", [&](){
                    nextState = EGamestates::management;
                }),
        new Button({300, 255}, {685, 830}, "assets/menu-exit.png", [&](){
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

void MainMenu::additionalResizes() {

}
