#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <string>

class Rectangle : public sf::RectangleShape {
private:
    sf::Texture tex;

public:
    Rectangle(const sf::Vector2f& size, const sf::Vector2f& position,
              std::string texturePath);
};

#endif
