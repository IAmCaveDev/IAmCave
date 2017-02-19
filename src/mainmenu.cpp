#include "mainmenu.h"
#include "button.h"
#include "game.h"

MainMenu::MainMenu(Game& gameRef) : GameState(gameRef) {
    
    std::function<void()> start = [&](){
       game.setCurrentGameState(EGamestates::management);
    };

    std::function<void()> options = [](){

    };

    std::function<void()> quit = [&](){
        game.getWindow().close();
    };

    buttons = {
        new Button({200,50},std::string("assets/fuck.png"),{200,100}, start),
        new Button({200,50},std::string("assets/fuck.png"),{200,200}, options),
        new Button({200,50},std::string("assets/fuck.png"),{200,300}, quit)
    };

}
