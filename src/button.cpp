#include "button.h"

Button::Button(const TransformedVector<>& size,
               const TransformedVector<>& newPosition,
               std::string texPath, std::function<void()> newCallback,
               std::function<void()> newAltCallback)
               : Textbox(size, newPosition, texPath){
    init(texPath, newCallback, newAltCallback);
}

Button::Button(const TransformedVector<>& size,
               const TransformedVector<>& newPosition,
               std::string texPath, std::function<void()> newCallback,
               std::function<void()> newAltCallback,
               std::string newText, int padding, int newTextSize,
               sf::Color newTextColor, sf::Text::Style newTextStyle)
               : Textbox(size, newPosition, texPath, newText, padding,
                         newTextSize, newTextColor, newTextStyle){
    init(texPath, newCallback, newAltCallback);
}

void Button::init(std::string texPath, std::function<void()> newCallback,
                  std::function<void()> newAltCallback){
    if(!texPath.empty()){
        size_t dotPos = texPath.find(".");
        std::string hiTexPath = texPath.substr(0, dotPos) + "-h"
                                + texPath.substr(dotPos);
        std::string diTexPath = texPath.substr(0, dotPos) + "-d"
                                + texPath.substr(dotPos);

        if(!highlightedTex.loadFromFile(hiTexPath)){
            highlightedTex = tex;
        }
        if(!disabledTex.loadFromFile(diTexPath)){
            disabledTex = tex;
        }
    }

    callback = newCallback;
    altCallback = newAltCallback;
    clickable = true;
    isHighlighted = false;
    visible = true;
}

void Button::highlighted(const sf::Vector2i& mousePosition, bool useAlt){
    if(!clickable || !visible) return;
    if(isClicked(mousePosition)){
        if((useAlt && altCallback != nullptr) ||
           (!useAlt && callback != nullptr)){
            setTexture(&highlightedTex);
            isHighlighted = true;
            if (!buttonText.empty()) {
                Textbox::setText(buttonText);
            }
        }
    }
    return;
}

void Button::executed(const sf::Vector2i& mousePosition, bool useAlt){
    if(!clickable || !isHighlighted || !visible) return;
    if(isClicked(mousePosition)){
        if(useAlt && altCallback != nullptr){
            altCallback();
        }else if(callback != nullptr){
            callback();
        }
    }
    if(isHighlighted){
        setTexture(&tex);
        isHighlighted = false;
        if (!buttonText.empty()) {
            Textbox::setText(buttonText);
        }
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

bool Button::isClicked(const sf::Vector2i& mousePosition) {
    sf::Vector2i myPosition = sf::Vector2i(getTransformedPosition());
    if((mousePosition.x >= myPosition.x) &&
       (mousePosition.x <= myPosition.x + getTransformedSize().getX()) &&
       (mousePosition.y >= myPosition.y) &&
       (mousePosition.y <= myPosition.y + getTransformedSize().getY())){
        return true;
    } else {
        return false;
    }
}

void Button::setText(std::string newText) {
    buttonText = newText;
}
