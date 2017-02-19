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
        new Button({200,50},std::string("assets/fuck.png"),{200,100}, start),
        new Button({200,50},std::string("assets/fuck.png"),{200,200}, options),
        new Button({200,50},std::string("assets/fuck.png"),{200,300}, quit)
    };

}

MainMenu::~MainMenu(){
    for(auto& it : buttons){
        delete it;
    }
}

void MainMenu::update(){
    for(auto const& it : buttons){
        window.draw(*it);
    }
}

std::vector<Button*>& MainMenu::getButtons(){
    return buttons;
}
