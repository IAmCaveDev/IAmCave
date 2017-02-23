#include "textbox.h"
#include <iostream>

#include <stdexcept>

sf::Font Textbox::font;

Textbox::Textbox(const TransformedVector<>& size,
                 const TransformedVector<>& position, std::string texturePath,
                 std::string newText, int padding, int newTextSize,
                 sf::Color newTextColor,
                 sf::Text::Style newTextStyle) : Rectangle(size, position,
                                                           texturePath){
    if(newText.compare("") != 0){
        text = sf::Text(newText, font);
        text.setCharacterSize(newTextSize);
        text.setFillColor(newTextColor);
        text.setStyle(newTextStyle);
        text.setPosition(padding, padding);
        wrap();

        renderTex.create(size.getRealX(), size.getRealY());

        sf::Sprite texSprite(tex);

        renderTex.draw(texSprite);
        renderTex.draw(text);
        renderTex.display();

        setTexture(&renderTex.getTexture());
    }
}

void Textbox::wrap(){
    sf::Vector2f initialPos = text.getPosition();
    text.setPosition(getPosition());
    std::string string = text.getString();
    std::string output = string;
    size_t index = 0;
    size_t oIndex = index;

    while(index != std::string::npos){
        index = string.find(" ");

        if(index+1 > string.size()){
            break;
        }

        oIndex += index+1;
        string = string.substr(index+1);

        sf::Vector2i pos(text.findCharacterPos(oIndex));
        if(pos.x > (getTransformedSize().getX() + getTransformedPosition().getX())){
            output.insert(oIndex, "\n");
            text.setString(output);
            oIndex += 1;
        }
    }
    text.setPosition(initialPos);
}

void Textbox::setText(std::string newText){
    text.setString(newText);
    wrap();
}

void Textbox::display(sf::RenderWindow& win) const {
    win.draw(*this);
}

void Textbox::setFont(std::string fontPath){
    if(!font.loadFromFile(fontPath)){
        throw std::runtime_error("Failed to load font '" + fontPath + "'.");
    }
}