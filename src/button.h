#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <functional>
#include <string>

class Button : public sf::RectangleShape {
private:
    bool clickable;
    bool isHighlighted;

    std::function<void()> callback;
    sf::Texture buttontex;

public:
    Button(const sf::Vector2f& size, std::string texturePath,
           const sf::Vector2f& newposition, std::function<void()> newcallback);

    void highlighted(const sf::Vector2i& mousePosition);
    void executed(const sf::Vector2i& mousePosition);

};

#endif
