#include "button.h"

Button::Button(const TransformedVector<>& size,
               const TransformedVector<>& newPosition,
               std::string texturePath, std::function<void()> newCallback,
               std::function<void()> newAltCallback)
               : Textbox(size, newPosition, texturePath){
    init(texturePath, newCallback, newAltCallback);
}

Button::Button(const TransformedVector<>& size,
               const TransformedVector<>& newPosition,
               std::string texturePath, std::function<void()> newCallback,
               std::function<void()> newAltCallback,
               std::string newText, int padding, int newTextSize,
               sf::Color newTextColor, sf::Text::Style newTextStyle)
               : Textbox(size, newPosition, texturePath, newText, padding,
                         newTextSize, newTextColor, newTextStyle){
    init(texturePath, newCallback, newAltCallback);
}

void Button::init(std::string texturePath, std::function<void()> newCallback,
                  std::function<void()> newAltCallback){
    size_t dotPos = texturePath.find(".");
    std::string hitexturePath = texturePath.substr(0, dotPos) + "-h"
                            + texturePath.substr(dotPos);
    std::string ditexturePath = texturePath.substr(0, dotPos) + "-d"
                            + texturePath.substr(dotPos);

    if(!highlightedTex.loadFromFile(hitexturePath)){
        highlightedTex = tex;
    }
    if(!disabledTex.loadFromFile(ditexturePath)){
        disabledTex = tex;
    }

    callback = newCallback;
    altCallback = newAltCallback;
    clickable = true;
    isHighlighted = false;
    visible = true;
}

void Button::highlighted(const sf::Vector2i& mousePosition, bool useAlt){
    if(!clickable) return;
    sf::Vector2i myPosition = sf::Vector2i(getTransformedPosition());
    if((mousePosition.x >= myPosition.x) &&
       (mousePosition.x <= myPosition.x + getTransformedSize().getX()) &&
       (mousePosition.y >= myPosition.y) &&
       (mousePosition.y <= myPosition.y + getTransformedSize().getY())){
        if((useAlt && altCallback != nullptr) ||
           (!useAlt && callback != nullptr)){
            setTexture(&highlightedTex);
            isHighlighted = true;
        }
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
        }else if(callback != nullptr){
            callback();
        }
    }
    if(isHighlighted){
        setTexture(&tex);
        isHighlighted = false;
    }
    return;
}

void Button::setCallback(std::function<void()> newCallback){
    callback = newCallback;
}

void Button::setAltCallback(std::function<void()> newAltCallback){
    altCallback = newAltCallback;
}

void Button::setVisibility(bool newvis) {
    visible = newvis;
}

bool Button::getVisibility() {
    return visible;
}

void Button::setClickability(bool newclick) {
    clickable = newclick;
    if(clickable){
        setTexture(&tex);
    }else{
        setTexture(&disabledTex);
    }
}

bool Button::getClickability() {
    return clickable;
}
