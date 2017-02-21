#include "mainmenu.h"
#include "button.h"
#include "game.h"
#include "buttonfunctions.h"

MainMenu::MainMenu(Game& gameRef) : GameState(gameRef) {

    rectangles = {
        new Rectangle({1920, 1080}, {0, 0}, "assets/background.png")
    };

    buttons = {
        // new Button({200, 50}, {200, 400}, "assets/go.png",
                   // std::bind(&ButtonFunctions::MainMenu::start, game),
                   // nullptr,
        // "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod\
        // tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At\
        // vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren,\
        // no sea takimata sanctus est Lorem ipsum dolor sit amet.", 14, sf::Color::Black),
        // new Button({200, 50}, {200, 100}, "assets/play.png",
                   // std::bind(&ButtonFunctions::MainMenu::start, game)),
        new Button({200, 50}, {200, 200}, "assets/options.png",
                   ButtonFunctions::MainMenu::options),
        new Button({200, 50}, {200, 300}, "assets/exit.png",
                   std::bind(&ButtonFunctions::MainMenu::start, game))
    };

}
