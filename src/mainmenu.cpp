#include "mainmenu.h"
#include "button.h"
#include "game.h"
#include "buttonfunctions.h"

MainMenu::MainMenu(sf::RenderWindow& win) {

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/background.png")
    };

    buttons = {
        new Button({200, 50}, {200, 100}, "assets/play.png",
                std::bind(&Game::setCurrentGameState, std::ref(gameRef), EGamestates::management)),
        new Button({200, 50}, {200, 200}, "assets/options.png",
                   ButtonFunctions::MainMenu::options),
        new Button({200, 50}, {200, 300}, "assets/exit.png",
                std::bind(&sf::RenderWindow::close, std::ref(win)))
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
