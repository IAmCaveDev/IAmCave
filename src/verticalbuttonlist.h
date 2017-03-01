#ifndef VERTICALBUTTONLIST_H
#define VERTICALBUTTONLIST_H

#include <vector>
#include <utility>

#include "rectangle.h"
#include "button.h"

class VerticalButtonList : public Rectangle {
private:
    // (ID, Button*, sortingOrder)
    struct Info {
        int id;
        Button* button;
        int priority;
    };
    std::vector<Info> buttons;

    bool reverse;

    void sort();

public:
    VerticalButtonList(const TransformedVector<>& size,
                       const TransformedVector<>& newPosition,
                       std::string texPath, bool newReverse = false);

    ~VerticalButtonList();

    // priority is used to determine the position of the button in the list
    // 0 is positioned on top (if reverse false)
    void addButton(int id, Button* button, int priority);

    void removeButton(int id);

    void decreasePriorityOfAll(int n = 1);

    void display(sf::RenderWindow& win);
};

#endif
