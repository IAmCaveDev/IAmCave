#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "transformedvector.h"

class Rectangle : public sf::RectangleShape {
private:
    sf::Texture tex;

public:
    Rectangle(const TransformedVector<>& size,
              const TransformedVector<>& position, std::string texturePath);
};

#endif
