#include "button.h"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position,
               std::string texturePath, std::function<void()> newcallback)
               : Rectangle(size, position, texturePath){
    callback = newcallback;
    clickable = true;
    isHighlighted = false;
    setOutlineThickness(4);
}

void Button::highlighted(const sf::Vector2i& mousePosition){
    if(!clickable) return;
    sf::Vector2i myPosition = sf::Vector2i(getPosition());
    if((mousePosition.x >= myPosition.x) &&
       (mousePosition.x <= myPosition.x + getSize().x) &&
       (mousePosition.y >= myPosition.y) &&
       (mousePosition.y <= myPosition.y + getSize().y)){
        setOutlineColor(sf::Color::Red);
        isHighlighted = true;
    }
    return;
}

void Button::executed(const sf::Vector2i& mousePosition){
    if(!clickable || !isHighlighted) return;
    sf::Vector2i myPosition = sf::Vector2i(getPosition());
    if((mousePosition.x >= myPosition.x) &&
       (mousePosition.x <= myPosition.x + getSize().x) &&
       (mousePosition.y >= myPosition.y) &&
       (mousePosition.y <= myPosition.y + getSize().y)){
        callback();
    }else if(isHighlighted){
        setOutlineColor(sf::Color::White);
        isHighlighted = false;
    }
    return;
}
