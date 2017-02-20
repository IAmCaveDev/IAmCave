#include "rectangle.h"

Rectangle::Rectangle(const sf::Vector2f& size, const sf::Vector2f& position,
                     std::string texturePath) : sf::RectangleShape(size){
    tex.loadFromFile(texturePath);
    setTexture(&tex);
    setPosition(position);
}
