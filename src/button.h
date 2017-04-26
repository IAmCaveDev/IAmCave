#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <functional>
#include <string>

#include "transformedvector.h"
#include "textbox.h"

/**
 * A button with up to two functions.
 * Since the callback types are `std::function<void()>`, functions with
 * arguments can be used by using `std::bind`:
 * \code{.cpp}
 * std::bind(&someFunction, arg)
 * \endcode
 * If a reference needs to be passed as an argument `std::ref` needs to be used
 * because `std::bind` uses value semantics by default:
 * \code{.cpp}
 * std::bind(&someFunction, std::ref(arg))
 * \endcode
 */
class Button : public Textbox {
private:
    bool clickable;
    bool isHighlighted;
    bool visible;

    std::string buttonText = "";

    /**
     * First function of the button. Used for left clicks in main.
     */
    std::function<void()> callback;
    /**
     * Second function of the button. Used for right clicks in main.
     */
    std::function<void()> altCallback;

    sf::Texture highlightedTex;
    sf::Texture disabledTex;

    void init(std::string texPath, std::function<void()> newCallback,
              std::function<void()> newAltCallback);

public:
    /**
     * Constructs a Button without any text.
     * @param texPath The texture to be used. Highlighted and disabled versions
     * of the texture will be automatically loaded by appending "-h" and "-d"
     * respectively to the filename.
     * @param newCallback The first function of the button. Can be nullptr.
     * @param newAltCallback The second function of the button. Can be nullptr.
     * @see Rectangle
     * @see Textbox
     */
    Button(const TransformedVector<>& size,
           const TransformedVector<>& newPosition,
           std::string texPath, std::function<void()> newCallback,
           std::function<void()> newAltCallback = nullptr);

    /**
     * Constructs a Button with text.
     * @param texPath The texture to be used. Highlighted and disabled versions
     * of the texture will be automatically loaded by appending "-h" and "-d"
     * respectively to the filename.
     * @param newCallback The first function of the button. Can be nullptr.
     * @param newAltCallback The second function of the button. Can be nullptr.
     * @see Rectangle
     * @see Textbox
     */
    Button(const TransformedVector<>& size,
           const TransformedVector<>& newPosition,
           std::string texPath, std::function<void()> newCallback,
           std::function<void()> newAltCallback, std::string newText,
           int padding = 5, int newTextSize = 20,
           sf::Color newTextColor = sf::Color::White,
           sf::Text::Style newTextStyle = sf::Text::Style::Regular);

    /**
     * Checks if the mouse is in the Button's bounds, if so highlights it.
     * If the used callback is a nullptr or clickable is false this function
     * does nothing.
     * @param mousePosition The mouse position.
     * @param useAlt If false uses callback, if true uses altCallback.
     */
    void highlighted(const sf::Vector2i& mousePosition, bool useAlt = false);
    /**
     * Checks if the mouse is in the Button's bounds, if so calls the callback
     * and unhighlights the button.
     * If the used callback is a nullptr this function does nothing.
     * @param mousePosition The mouse position.
     * @param useAlt If false uses callback, if true uses altCallback.
     */
    void executed(const sf::Vector2i& mousePosition, bool useAlt = false);

    /**
     * Sets the first function of the Button.
     * @param newCallback The callback to use.
     */
    void setCallback(std::function<void()> newCallback);
    /**
     * Sets the second function of the Button.
     * @param newAltCallback The callback to use.
     */
    void setAltCallback(std::function<void()> newAltCallback);

    /**
     * Sets the visibility of the button.
     */
    void setVisibility(bool newvis);
    /**
     * Returns the visibility of the button.
     */
    bool getVisibility();

    /**
     * Sets the clickability of the button.
     */
    void setClickability(bool newclick);
    /**
     * Gets the clickability of the button.
     */
    bool getClickability();

    bool isClicked(const sf::Vector2i& mousePosition);

    void setText(std::string newText);
};

#endif
