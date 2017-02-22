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
    wrap();
}

void Textbox::wrap(){
    std::string string = text.getString();
    std::string output = string;
    size_t index = 0;
    size_t oIndex = index;
    size_t lastIndex = index;

    while(index != std::string::npos){
        index = string.find(" ");

        if(index+1 > string.size()){
            break;
        }

        oIndex += index+1;
        string = string.substr(index+1);

        sf::Vector2i pos(text.findCharacterPos(oIndex));
        if(pos.x > (getTransformedSize().getX() + getTransformedPosition().getX())){
            output.insert(lastIndex, "\n");
            text.setString(output);
            oIndex += 1;
        }
        lastIndex = oIndex;
    }
    text.setString(output);
}

void Textbox::setText(std::string newText){
    text.setString(newText);
    wrap();
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
