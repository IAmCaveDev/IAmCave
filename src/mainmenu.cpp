#include "mainmenu.h"
#include "button.h"

void mainMenu(sf::RenderWindow& win) {
    std::function<void()> start = [](){};
    std::function<void()> options = [](){};
    std::function<void()> quit = [&](){
        win.close();
    };

    Button menuButtons[3] = {
        Button({200,50},std::string("assets/fuck.png"),{200,100}, []() {}),
        Button({200,50},std::string("assets/fuck.png"),{200,200}, []() {}),
        Button({200,50},std::string("assets/fuck.png"),{200,300}, []() {})
    };

    while (win.isOpen()) {

        sf::Event event;

        while (win.pollEvent(event)) {

            switch (event.type) {

            case sf::Event::Closed:
                win.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    for (int i = 0; i < 3; i++) {
                        menuButtons[i].clicked(sf::Mouse::getPosition());
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
