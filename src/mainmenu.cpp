#include "mainmenu.h"
#include "button.h"
#include "game.h"

void mainMenu(sf::RenderWindow& win) {
    std::function<void()> start = [](){

    };

    std::function<void()> options = [](){

    };

    std::function<void()> quit = [&](){
        win.close();
    };

    Button menuButtons[3] = {
        Button({200,50},std::string("assets/fuck.png"),{200,100}, start),
        Button({200,50},std::string("assets/fuck.png"),{200,200}, options),
        Button({200,50},std::string("assets/fuck.png"),{200,300}, quit)
    };

    while (win.isOpen()) {

        sf::Event event;

        while (win.pollEvent(event)) {

            if(event.type == sf::Event::Closed){
                win.close();
                break;
            }else if(event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left) {
                    for (int i = 0; i < 3; i++) {
                        sf::Vector2i pos = sf::Mouse::getPosition(win);
                        menuButtons[i].clicked(pos);
                    }
                }
            }
        }

        win.clear(sf::Color::Black);

        for (int i = 0; i < 3; ++i) {
            win.draw(menuButtons[i]);
        }

        win.display();
    }
}
