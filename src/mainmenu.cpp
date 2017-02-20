#include "mainmenu.h"
#include "button.h"
#include "game.h"

MainMenu::MainMenu(Game& gameRef) : GameState(gameRef) {

    drawables = {
    };

    std::function<void()> start = [&](){
       game.setCurrentGameState(EGamestates::management);
    };

    std::function<void()> options = [](){

    };

    std::function<void()> quit = [&](){
        game.getWindow().close();
    };

    buttons = {
        new Button({200,50},{200,100},std::string("assets/fuck.png"), start),
        new Button({200,50},{200,200},std::string("assets/fuck.png"), options),
        new Button({200,50},{200,300},std::string("assets/fuck.png"), quit)
    };

}
