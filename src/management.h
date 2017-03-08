#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "gamestate.h"
#include "actionfactory.h"
#include "action.h"
#include "verticalbuttonlist.h"

/**
 * The management phase of the game.
 * The user can select actions/etc here.
 */
class Management : public GameState {
private:
    ActionFactory actionFactory;
    std::unique_ptr<Action> currentAction;

    VerticalButtonList* actionDisplay;

public:
    Management() = delete;
    explicit Management(Game& gameRef);

    void setCurrentAction(EActions newaction, short duration);
    Action& getCurrentAction();
    void pushCurrentAction();
    void deleteCurrentAction();

    /**
     * Gets all cavemen that are not doing anything.
     */
    std::vector<Caveman*> getIdlingTribe();
    /**
     * Gets the VerticalButtonList used to display the actions in progress.
     */
    VerticalButtonList& getActionDisplay();

    /**
     * Displays all Rectangles and Button and the Buttons from the tribe in
     * Game.
     * @param win The window to draw on.
     */
    void display(sf::RenderWindow& win);
};

#endif
