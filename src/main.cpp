#include "game.h"
#include "transformedvector.h"
#include "textbox.h"

#include <iostream>

int main(int argc, char *argv[]){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "IAmCave");

    sf::View view(window.getDefaultView());

    sf::Vector2u size = window.getSize();
    TransformedVector<>::updateWinSize(size.x, size.y);

    try {
        Textbox::setFont("assets/arial.ttf");
    }
    catch(std::runtime_error err){
        window.close();
        return 1;
    }

    Game game(window);

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

                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    pos = sf::Vector2i(window.mapPixelToCoords(pos));

                    for(auto& it : buttons){
                        if(event.mouseButton.button == sf::Mouse::Left){
                            it->highlighted({pos.x, pos.y});
                        }else if(event.mouseButton.button == sf::Mouse::Right){
                            it->highlighted({pos.x, pos.y}, true);
                        }
                    }

                    std::vector<Caveman*> cavemen;
                    cavemen = game.getTribe();

                    for(auto& it : cavemen){
                        if(event.mouseButton.button == sf::Mouse::Left){
                            it->getButton().highlighted({pos.x, pos.y});
                        }else if(event.mouseButton.button == sf::Mouse::Right){
                            it->getButton().highlighted({pos.x, pos.y}, true);
                        }
                    }
                }

            }else if(event.type == sf::Event::MouseButtonReleased){
                if(event.mouseButton.button == sf::Mouse::Left ||
                   event.mouseButton.button == sf::Mouse::Right){
                    std::vector<Button*> buttons;
                    buttons = game.getCurrentGameState().getButtons();

                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    pos = sf::Vector2i(window.mapPixelToCoords(pos));

                    for(auto& it : buttons){
                        if(event.mouseButton.button == sf::Mouse::Left){
                            it->executed({pos.x, pos.y});
                        }else if(event.mouseButton.button == sf::Mouse::Right){
                            it->executed({pos.x, pos.y}, true);
                        }
                    }

                    std::vector<Caveman*> cavemen;
                    cavemen = game.getTribe();

                    for(auto& it : cavemen){
                        if(event.mouseButton.button == sf::Mouse::Left){
                            it->getButton().executed({pos.x, pos.y});
                        }else if(event.mouseButton.button == sf::Mouse::Right){
                            it->getButton().executed({pos.x, pos.y}, true);
                        }
                    }
                }

            }else if(event.type == sf::Event::Resized){
                sf::Vector2u size = window.getSize();

                TransformedVector<>::updateWinSize(size.x, size.y);

                // Force 16:9 aspect ratio
                view = sf::View(sf::FloatRect(0, 0, size.x, size.y));

                if(size.x/16 == size.y/9){
                    view = sf::View(sf::FloatRect(0, 0, size.x, size.y));
                }else if(size.x/16 < size.y/9){
                    view.setViewport(sf::FloatRect(
                                     0, ((size.y - size.x*(9.0/16.0))/2)/size.y,
                                     1, (size.x*(9.0/16.0))/size.y));
                }else{
                    view.setViewport(sf::FloatRect(
                                     ((size.x - size.y*(16.0/9.0))/2)/size.x, 0,
                                     (size.y*(16.0/9.0))/size.x, 1));
                }
                window.setView(view);

                game.getCurrentGameState().onResize();
            }
        }

        window.clear(sf::Color::Black);

        game.display();

        window.display();
    }

    return 0;
}
