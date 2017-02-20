#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <functional>
#include <string>

#include "rectangle.h"

class Button : public Rectangle {
private:
    bool clickable;
    bool isHighlighted;

    std::function<void()> callback;
    std::function<void()> altCallback;
    sf::Texture buttontex;

public:
    Button(const sf::Vector2f& size, const sf::Vector2f& newposition,
           std::string texturePath, std::function<void()> newCallback,
           std::function<void()> newAltCallback = nullptr);

    void highlighted(const sf::Vector2i& mousePosition);
    void executed(const sf::Vector2i& mousePosition, bool useAlt = false);

};

#endif
