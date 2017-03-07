#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include "gamestate.h"
#include "mainmenu.h"
#include "management.h"
#include "roundend.h"

class GameManager {
private:
    Game game;

    GameState* currentGameState;
    MainMenu mainMenu;
    Management management;
    RoundEnd roundEnd;

public:
    GameManager() = delete;
    explicit GameManager(std::string savePath, sf::RenderWindow& win);

    void update();
};

#endif
