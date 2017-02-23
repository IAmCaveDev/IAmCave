#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "transformedvector.h"

class Rectangle : public sf::RectangleShape {
private:
    TransformedVector<> transformedSize;
    TransformedVector<> transformedPosition;

protected:
    sf::Texture tex;

public:
    Rectangle(const TransformedVector<>& size,
              const TransformedVector<>& position, std::string texturePath);

    void display(sf::RenderWindow& win) const;

    TransformedVector<> getTransformedSize();
    void setTransformedSize(TransformedVector<> newPosition);

    TransformedVector<> getTransformedPosition();
    void setTransformedPosition(TransformedVector<> newPosition);
};

#endif
