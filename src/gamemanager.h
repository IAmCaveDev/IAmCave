#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>

#include "game.h"
#include "gamestate.h"
#include "mainmenu.h"
#include "management.h"
#include "roundend.h"
#include "winscreen.h"
#include "losescreen.h"

/**
 * Manages information about the game and it's states.
 */
class GameManager {
private:
    sf::RenderWindow& window;

    Game game;

    GameState* currentGameState;
    MainMenu mainMenu;
    Management management;
    RoundEnd roundEnd;
    WinScreen winScreen;
    LoseScreen loseScreen;

public:
    GameManager() = delete;

    /**
     * Constructor.
     * @param savePath The save file to load. Use "" to start a new game.
     * @param win The window to use for drawing.
     */
    GameManager(std::string savePath, sf::RenderWindow& win);

    /**
     * Displays the currentGameState's rectangles.
     * Should be called every iteration of the game loop.
     * @see Rectangle
     */
    void display();

    /**
     * Handles the currentGameState.
     * Should be called every iteration of the game loop.
     */
    void update();

    /**
     * Getter for game.
     * @return A reference to the game object.
     */
    Game& getGame();

    /**
     * Getter for currentGameState.
     * @return A reference to the current gamestate.
     */
    GameState& getCurrentGameState();

    /**
     * Getter for window.
     * @return A reference to the SFML window.
     */
    sf::RenderWindow& getWindow();
};

#endif
