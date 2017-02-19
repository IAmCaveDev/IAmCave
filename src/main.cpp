#include "mainmenu.h"
#include "game.h"

int main(int argc, char *argv[]){
    sf::RenderWindow window(sf::VideoMode(800, 600), "IAmCave");

    Game game(window);
    MainMenu mainMenu(window, game);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                break;
            }else if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    std::vector<Button*> buttons;
                    if(game.isActive()){
                        buttons = game.getCurrentGameState().getButtons();
                    }else{
                        buttons = mainMenu.getButtons();
                    }

                    for(auto& it : buttons){
                        sf::Vector2i pos = sf::Mouse::getPosition(window);
                        it->highlighted(pos);
                    }
                }
            }else if(event.type == sf::Event::MouseButtonReleased){
                if(event.mouseButton.button == sf::Mouse::Left){
                    std::vector<Button*> buttons;
                    if(game.isActive()){
                        buttons = game.getCurrentGameState().getButtons();
                    }else{
                        buttons = mainMenu.getButtons();
                    }

                    for(auto& it : buttons){
                        sf::Vector2i pos = sf::Mouse::getPosition(window);
                        it->executed(pos);
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        if(game.isActive()){
            game.update();
        }else{
            mainMenu.update();
        }

        window.display();
    }

    return 0;
}
