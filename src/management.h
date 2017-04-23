#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "gamestate.h"
#include "actionfactory.h"
#include "action.h"
#include "verticalbuttonlist.h"
#include "textbox.h"
#include "resourcedisplay.h"

/**
 * The management phase of the game.
 * The user can select actions/etc here.
 */
class Management : public GameState {
private:
    ActionFactory actionFactory;
    /**
     * Stores the Action object the user is currently modifying.
     */
    std::unique_ptr<Action> currentAction;

    VerticalButtonList* actionDisplay;
    ResourceDisplay* resourceDisplay;

    /**
     * Stores the name of the Tech the user is thinking about researching.
     */
    std::string activeTech;

    Rectangle* grass;

    Textbox* textbox;

public:
    Management() = delete;
    explicit Management(Game& gameRef);
    /**
     * Uses actionFactory to create a new currentAction.
     * @param newaction Type of the Action to be created.
     * @param duration Duration of the Action to be created.
     */
    void setCurrentAction(EActions newaction, short duration);
    /**
     * Returns a reference to the current Action.
     */
    Action& getCurrentAction();
    /**
     * Moves the current Action into the actions vector of game.
     */
    void pushCurrentAction();
    /**
     * Deletes the current Action by calling unique_ptr::reset.
     */
    void deleteCurrentAction();
    /**
     * Sets the active Tech. Gets called when User clicks a Tech in Techtree.
     */
    void setActiveTech(std::string newTech);
    /**
     * @return the active Tech
     */
    std::string getActiveTech();
    /**
     * Doesn't really delete the string, just sets it to "".
     */
    void deleteActiveTech();
    /**
     * Gets all cavemen that are not doing anything.
     */
    std::vector<std::shared_ptr<Caveman>> getIdlingTribe();
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
    /**
     * Sets the text of the state's textbox.
     */
    void setTextboxText(std::string str);
    /**
     * Resets the state's textbox to display a standard message.
     */
    void resetTextbox();
    /**
     * Returns the Techtree Object from Class variable game.
     */
    Techtree& getTechtree();
    /**
     * Calls onResize() functions of grass, resourceDisplay and techtree.
     */
    void additionalResizes();
};

#endif
