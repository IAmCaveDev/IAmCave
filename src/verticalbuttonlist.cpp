#include "verticalbuttonlist.h"

VerticalButtonList::VerticalButtonList(const TransformedVector<>& size,
                                       const TransformedVector<>& newPosition,
                                       std::string texPath, bool newReverse)
                                       : Rectangle(size, newPosition, texPath){
    reverse = newReverse;
}

VerticalButtonList::~VerticalButtonList(){
    for (auto& it : buttons) {
        delete it.first;
    }
}


void VerticalButtonList::addButton(Button* button, unsigned int priority){
    buttons.push_back(std::pair<Button*, int>(button, priority));
}

void VerticalButtonList::display(sf::RenderWindow& win){
    // sort vector by second object of pair
    typedef const std::pair<Button*, int> bpPair;
    std::sort(buttons.begin(), buttons.end(), [](bpPair& lhs, bpPair& rhs){
        return lhs.second < rhs.second;
    });

    int i = 0;
    for(auto& it : buttons){
        int width = getTransformedSize().getRealX();

        it.first->setTransformedSize({width, width});

        TransformedVector<> newPos =
                {getTransformedPosition().getRealX(),
                 getTransformedPosition().getRealY() + width * i};
        it.first->setTransformedPosition(newPos);

        i += 1;

        it.first->display(win);
    }
}
