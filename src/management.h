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
    std::shared_ptr<Action> currentAction;

    VerticalButtonList* actionDisplay;
    ResourceDisplay* resourceDisplay;

    std::string activeTech;

    Rectangle* grass;

    Textbox* textbox;

public:
    Management() = delete;
    explicit Management(Game& gameRef);

    void setCurrentAction(EActions newaction, short duration);
    Action& getCurrentAction();
    void pushCurrentAction();
    void deleteCurrentAction();

    void setActiveTech(std::string newTech);
    std::string getActiveTech();
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

    Techtree& getTechtree();

    void additionalResizes();
};

#endif
