#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <functional>
#include <string>

#include "transformedvector.h"
#include "textbox.h"

class Button : public Textbox {
private:
    bool clickable;
    bool isHighlighted;
    bool visible;

    std::function<void()> callback;
    std::function<void()> altCallback;

    sf::Texture highlightedTex;
    sf::Texture disabledTex;

    void init(std::string texturePath, std::function<void()> newCallback,
              std::function<void()> newAltCallback);

public:
    Button(const TransformedVector<>& size,
           const TransformedVector<>& newPosition,
           std::string texturePath, std::function<void()> newCallback,
           std::function<void()> newAltCallback = nullptr);

    Button(const TransformedVector<>& size,
           const TransformedVector<>& newPosition,
           std::string texturePath, std::function<void()> newCallback,
           std::function<void()> newAltCallback, std::string newText,
           int padding = 5, int newTextSize = 20,
           sf::Color newTextColor = sf::Color::Black,
           sf::Text::Style newTextStyle = sf::Text::Style::Regular);

    void highlighted(const sf::Vector2i& mousePosition, bool useAlt = false);
    void executed(const sf::Vector2i& mousePosition, bool useAlt = false);

    void setCallback(std::function<void()> newCallback);
    void setAltCallback(std::function<void()> newAltCallback);

    void setVisibility(bool newvis);
    bool getVisibility();

    void setClickability(bool newclick);
    bool getClickability();
};

#endif
