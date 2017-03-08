#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

#include "rectangle.h"


/**
 * A Rectangle with text.
 */
class Textbox : public Rectangle {
private:
    static sf::Font font;
    sf::Text text;
    sf::RenderTexture renderTex;

    /**
     * Wraps the text at the current width of the Textbox.
     */
    void wrap();

protected:
    /**
     * Textboxes constructed with this constructor will not be able to have any
     * text.
     * Required by Button. Same constructor as Rectangle.
     * @see Button
     * @see Rectangle
     */
    Textbox(const TransformedVector<>& size,
            const TransformedVector<>& position, std::string texturePath);

public:
    /**
     * Constructs a Textbox.
     * @param newText The text to use.
     * @param padding The padding from the top left corner of the Textbox in
     * pixels.
     * @param newTextSize The size of the text in pixels.
     * @param newTextColor The color of the text.
     * @param newTextStyle The style of the text.
     */
    Textbox(const TransformedVector<>& size,
            const TransformedVector<>& position, std::string texturePath,
            std::string newText, int padding = 5, int newTextSize = 20,
            sf::Color newTextColor = sf::Color::Black,
            sf::Text::Style newTextStyle = sf::Text::Style::Regular);

    /**
     * Sets the text and calls wrap.
     * @param newText The text to use.
     */
    void setText(std::string newText);

    /**
     * Displays the Textbox.
     * @param win The window to draw on.
     */
    void display(sf::RenderWindow& win) const;

    /**
     * Sets the font for all Textboxes.
     * @param fontPath The path to the font file.
     */
    static void setFont(std::string fontPath);
};

#endif
