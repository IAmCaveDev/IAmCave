#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>

#include "game.h"
#include "gamestate.h"
#include "mainmenu.h"
#include "management.h"
#include "roundend.h"

class GameManager {
private:
    sf::RenderWindow& window;

    Game game;

    GameState* currentGameState;
    MainMenu mainMenu;
    Management management;
    RoundEnd roundEnd;

public:
    GameManager() = delete;
    GameManager(std::string savePath, sf::RenderWindow& win);

    void display();

    void update();

    Game& getGame();

    GameState& getCurrentGameState();

    sf::RenderWindow& getWindow();
};

#endif
