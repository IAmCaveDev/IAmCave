#include "textbox.h"

#include <stdexcept>

sf::Font Textbox::font;

Textbox::Textbox(const TransformedVector<>& size,
                 const TransformedVector<>& position, std::string texturePath,
                 std::string newText, int newTextSize, sf::Color newTextColor,
                 sf::Text::Style newTextStyle) : Rectangle(size, position,
                                                           texturePath){

    text = sf::Text(newText, font);
    text.setCharacterSize(newTextSize);
    text.setFillColor(newTextColor);
    text.setStyle(newTextStyle);
    text.setPosition(position);
}

std::string wrap(std::string string, int width){
    return string;
}

void Textbox::setText(std::string newText){
    text.setString(newText);
}

void Textbox::display(sf::RenderWindow& win) const {
    win.draw(*this);
    win.draw(text);
}

void Textbox::setFont(std::string fontPath){
    if(!font.loadFromFile(fontPath)){
        throw std::runtime_error("Failed to load font '" + fontPath + "'.");
    }
}
