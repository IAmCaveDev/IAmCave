#include "rectangle.h"

Rectangle::Rectangle(const TransformedVector<>& size,
                     const TransformedVector<>& position,
                     std::string texturePath) : sf::RectangleShape(size){
    tex.loadFromFile(texturePath);
    setTexture(&tex);
    setPosition(position);
}
