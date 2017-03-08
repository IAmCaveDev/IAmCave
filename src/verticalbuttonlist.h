#ifndef VERTICALBUTTONLIST_H
#define VERTICALBUTTONLIST_H

#include <vector>
#include <utility>

#include "rectangle.h"
#include "button.h"

/**
 * A vertical list of buttons.
 * Buttons are sorted by their priority with the lowest priority on top if
 * reverse is false.
 */
class VerticalButtonList : public Rectangle {
private:
    /**
     * Used to store info about a button inside a VerticalButtonList.
     */
    struct Info {
        /**
         * The ID of the button (used to remove it).
         */
        int id;
        /**
         * Pointer to the button to display.
         */
        Button* button;
        /**
         * Priority used to order the list.
         */
        int priority;
    };
    /**
     * List of buttons and their additional info.
     */
    std::vector<Info> buttons;

    /**
     * If true reverses the list with the highest priority on top.
     */
    bool reverse;

    /**
     * Sorts the list by priority.
     */
    void sort();

public:
    /**
     * Constructs a new VerticalButtonList and sets reverse.
     * Otherwise same constructor as Rectangle.
     * @see Rectangle
     */
    VerticalButtonList(const TransformedVector<>& size,
                       const TransformedVector<>& newPosition,
                       std::string texturePath, bool newReverse = false);

    /**
     * Deletes every Button remaining in it's list.
     */
    ~VerticalButtonList();

    /**
     * Adds a button to the list.
     */
    void addButton(int id, Button* button, int priority);

    /**
     * Removes a button.
     * @param id Removes the button with this id.
     */
    void removeButton(int id);

    /**
     * Decreases the priority of all.
     * @param n Decrement.
     */
    void decreasePriorityOfAll(int n = 1);

    /**
     * Draws the VerticalButtonList's buttons.
     * @param win The window to draw on.
     */
    void display(sf::RenderWindow& win);
};

#endif
