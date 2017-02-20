#include "button.h"

Button::Button(const TransformedVector<>& size,
               const TransformedVector<>& newPosition,
               std::string texturePath, std::function<void()> newCallback,
               std::function<void()> newAltCallback)
               : Rectangle(size, newPosition, texturePath){
    callback = newCallback;
    altCallback = newAltCallback;
    clickable = true;
    isHighlighted = false;
    setOutlineThickness(4);
}

void Button::highlighted(const sf::Vector2i& mousePosition){
    if(!clickable) return;
    sf::Vector2i myPosition = sf::Vector2i(getTransformedPosition());
    if((mousePosition.x >= myPosition.x) &&
       (mousePosition.x <= myPosition.x + getTransformedSize().getX()) &&
       (mousePosition.y >= myPosition.y) &&
       (mousePosition.y <= myPosition.y + getTransformedSize().getY())){
        setOutlineColor(sf::Color::Red);
        isHighlighted = true;
    }
    return;
}

void Button::executed(const sf::Vector2i& mousePosition, bool useAlt){
    if(!clickable || !isHighlighted) return;
    sf::Vector2i myPosition = sf::Vector2i(getTransformedPosition());
    if((mousePosition.x >= myPosition.x) &&
       (mousePosition.x <= myPosition.x + getTransformedSize().getX()) &&
       (mousePosition.y >= myPosition.y) &&
       (mousePosition.y <= myPosition.y + getTransformedSize().getY())){
        if(useAlt && altCallback != nullptr){
            altCallback();
        }else{
            callback();
        }
    }else if(isHighlighted){
        setOutlineColor(sf::Color::White);
        isHighlighted = false;
    }
    return;
}
