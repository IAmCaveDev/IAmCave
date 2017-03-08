#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "button.h"
#include "rectangle.h"
#include "game.h"

/**
 * All possible game states.
 * Quit is not a real object. As soon as quit is specified as the next game
 * state the game will be closed.
 */
enum EGamestates {
    mainMenu,
    management,
    roundEnd,
    quit
};

/**
 * A state the game can be in.
 */
class GameState {
protected:
    Game& game;

    std::vector<Rectangle*> rectangles;
    std::vector<Button*> buttons;

    EGamestates type;
    EGamestates nextState;

public:
    GameState() = delete;
    /**
     * Constructs a GameState.
     * @param gameRef A reference to the game the GameState is associated with.
     */
    explicit GameState(Game& gameRef);
    /**
     * Deletes all Rectangles and Buttons.
     */
    ~GameState();

    /**
     * Resizes and repositions all Rectangles and Buttons.
     * Also transforms the Buttons of the tribe in Game.
     */
    void onResize();

    /**
     * Gets the list of Buttons in the GameState.
     */
    std::vector<Button*>& getButtons();
    /**
     * Gets the list of Rectangles in the GameState.
     */
    std::vector<Rectangle*>& getRectangles();

    /**
     * Displays the game state.
     * @param win The window to draw on.
     */
    virtual void display(sf::RenderWindow& win) = 0;

    /**
     * Gets the type of the GameState.
     */
    EGamestates getType();

    /**
     * Gets the next state.
     * Is equal to the type of the current GameState as long as the state should
     * not be changed.
     */
    EGamestates getNextState();
    /**
     * Sets the next state.
     */
    void setNextState(EGamestates newNextState);
};

#endif
