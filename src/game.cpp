#include "game.h"

Game::Game(sf::RenderWindow* windowRef) : management(*this),
                                          roundEnd(*this){
    window = windowRef;
}
