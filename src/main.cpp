#include "game.h"
#include "transformedvector.h"

int main(int argc, char *argv[]){
    sf::RenderWindow window(sf::VideoMode(800, 600), "IAmCave");

    sf::Vector2u size = window.getSize();
    TransformedVector<>::updateWinSize(size.x, size.y);

    Game game(window);
    game.setCurrentGameState(EGamestates::mainMenu);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                break;
            }else if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left ||
                   event.mouseButton.button == sf::Mouse::Right){
                    std::vector<Button*> buttons;
                    buttons = game.getCurrentGameState().getButtons();
                    for(auto& it : buttons){
                        sf::Vector2i pos = sf::Mouse::getPosition(window);
                        it->highlighted(pos);
                    }
                }
            }else if(event.type == sf::Event::MouseButtonReleased){
                std::vector<Button*> buttons;
                buttons = game.getCurrentGameState().getButtons();
                for(auto& it : buttons){
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    if(event.mouseButton.button == sf::Mouse::Left){
                        it->executed(pos);
                    }else if(event.mouseButton.button == sf::Mouse::Right){
                        it->executed(pos, true);
                    }
                }
            }else if(event.type == sf::Event::Resized){
                sf::Vector2u size = window.getSize();
                TransformedVector<>::updateWinSize(size.x, size.y);
            }
        }

        window.clear(sf::Color::Black);

        game.update();

        window.display();
    }

    return 0;
}
