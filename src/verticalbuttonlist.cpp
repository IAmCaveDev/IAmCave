#include "verticalbuttonlist.h"

VerticalButtonList::VerticalButtonList(const TransformedVector<>& size,
                                       const TransformedVector<>& newPosition,
                                       std::string texturePath, bool newReverse)
                                       : Rectangle(size, newPosition, texturePath){
    reverse = newReverse;
}

VerticalButtonList::~VerticalButtonList(){
    for (auto& it : buttons) {
        delete it.button;
    }
}

void VerticalButtonList::sort(){
    // sort vector by priority
    std::sort(buttons.begin(), buttons.end(), [](Info& lhs, Info& rhs){
        return lhs.priority < rhs.priority;
    });
}


void VerticalButtonList::addButton(int id, Button* button, int priority){
    buttons.push_back({id, button, priority});
    sort();
}

void VerticalButtonList::removeButton(int id){
    for(int i = 0; i < buttons.size(); ++i){
        if(buttons.at(i).id == id){
            delete buttons.at(i).button;
            buttons.erase(buttons.begin() + i);
        }
    }
}

void VerticalButtonList::display(sf::RenderWindow& win){
    int i = 0;
    for(auto& it : buttons){
        int width = getTransformedSize().getRealX();

        it.button->setTransformedSize({width, width});

        TransformedVector<> newPos =
                {getTransformedPosition().getRealX(),
                 getTransformedPosition().getRealY() + width * i};
        it.button->setTransformedPosition(newPos);

        i += 1;

        it.button->display(win);
    }
}
