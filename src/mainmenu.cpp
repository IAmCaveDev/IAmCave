#include "mainmenu.h"
#include "button.h"
#include "game.h"

MainMenu::MainMenu(sf::RenderWindow& windowRef, Game& gameRef) :
                                                        window(windowRef),
                                                        game(gameRef){
    std::function<void()> start = [&](){
       game.setActive(true);
    };

    std::function<void()> options = [](){

    };

    std::function<void()> quit = [&](){
        window.close();
    };

    buttons = {
        Button({200,50},std::string("assets/fuck.png"),{200,100}, start),
        Button({200,50},std::string("assets/fuck.png"),{200,200}, options),
        Button({200,50},std::string("assets/fuck.png"),{200,300}, quit)
    };

}

void MainMenu::update(){
    for(auto const& it : buttons){
        window.draw(it);
    }
}

const std::vector<Button>& MainMenu::getButtons() const {
    return buttons;
}
