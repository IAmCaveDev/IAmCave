#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "transformedvector.h"

class Rectangle : public sf::RectangleShape {
private:
    sf::Texture tex;

    TransformedVector<> transformedSize;
    TransformedVector<> transformedPosition;

public:
    Rectangle(const TransformedVector<>& size,
              const TransformedVector<>& position, std::string texturePath);

    TransformedVector<> getTransformedSize();
    void setTransformedSize(TransformedVector<> newPosition);

    TransformedVector<> getTransformedPosition();
    void setTransformedPosition(TransformedVector<> newPosition);
};

#endif
