#ifndef VERTICALBUTTONLIST_H
#define VERTICALBUTTONLIST_H

#include <vector>
#include <utility>

#include "rectangle.h"
#include "button.h"

class VerticalButtonList : public Rectangle {
private:
    std::vector<std::pair<Button*, int>> buttons;

    bool reverse;

public:
    VerticalButtonList(const TransformedVector<>& size,
                       const TransformedVector<>& newPosition,
                       std::string texPath, bool newReverse = false);

    ~VerticalButtonList();

    // priority is used to determine the position of the button in the list
    // 0 is positioned on top (if reverse false)
    void addButton(Button* button, unsigned int priority);

    void decreasePriorityOfAll(int n = 1);

    void display(sf::RenderWindow& win);
};

#endif
