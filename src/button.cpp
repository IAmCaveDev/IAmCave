#include "button.h"

Button::Button(const sf::Vector2f& size, std::string texturePath,
               const sf::Vector2f& newposition,
               std::function<void()> newcallback) : sf::RectangleShape(size){
    buttontex.loadFromFile(texturePath);
    setTexture(&buttontex);
    setPosition(newposition);
    callback = newcallback;
    clickable = true;
    isHighlighted = false;
    setOutlineColor(sf::Color::Red);
}

void Button::highlighted(const sf::Vector2i& mousePosition){
    if(!clickable) return;
    sf::Vector2i myPosition = sf::Vector2i(getPosition());
    if((mousePosition.x >= myPosition.x) &&
       (mousePosition.x <= myPosition.x + getSize().x) &&
       (mousePosition.y >= myPosition.y) &&
       (mousePosition.y <= myPosition.y + getSize().y)){
        setOutlineThickness(10);
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
        setOutlineThickness(0);
        isHighlighted = false;
    }
    return;
}
