#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

#include "rectangle.h"


class Textbox : public Rectangle {
private:
    static sf::Font font;
    sf::Text text;

    void wrap();

public:
    Textbox(const TransformedVector<>& size,
            const TransformedVector<>& position, std::string texturePath,
            std::string newText, int newTextSize = 14,
            sf::Color newTextColor = sf::Color::White,
            sf::Text::Style newTextStyle = sf::Text::Style::Regular);

    void setText(std::string newText);

    void display(sf::RenderWindow& win) const;

    static void setFont(std::string fontPath);
};

#endif
