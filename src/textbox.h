#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

#include "rectangle.h"


class Textbox : public Rectangle {
private:
    static sf::Font font;
    sf::Text text;
    sf::RenderTexture renderTex;

    void wrap();

protected:
    // Textbox constructed with this ctor will never be able to have text
    // (for buttons)
    Textbox(const TransformedVector<>& size,
            const TransformedVector<>& position, std::string texturePath);

public:
    Textbox(const TransformedVector<>& size,
            const TransformedVector<>& position, std::string texturePath,
            std::string newText, int padding = 5, int newTextSize = 20,
            sf::Color newTextColor = sf::Color::Black,
            sf::Text::Style newTextStyle = sf::Text::Style::Regular);

    void setText(std::string newText);

    void display(sf::RenderWindow& win) const;

    static void setFont(std::string fontPath);
};

#endif
