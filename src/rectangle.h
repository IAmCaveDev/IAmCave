#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "transformedvector.h"

/**
 * A rectangle.
 * Makes sf::RectangleShape use TransformedVectors and load a texture from a
 * file.
 */
class Rectangle : public sf::RectangleShape {
private:
    TransformedVector<> transformedSize;
    TransformedVector<> transformedPosition;

protected:
    sf::Texture tex;

public:
    /*
     * Constructs a rectangle.
     * @param size The size at \f$(x_0, y_0)\f$ window resolution.
     * @param position The position at \f$(x_0, y_0)\f$ window resolution.
     * @param texturePath The path to the texture to be applied to the
     * rectangle.
     */
    Rectangle(const TransformedVector<>& size,
              const TransformedVector<>& position, std::string texturePath);

    /**
     * Draws the rectangle on a window.
     * @param win The window to draw on.
     */
    void display(sf::RenderWindow& win) const;

    /**
     * Gets the size as a TransformedVector.
     */
    TransformedVector<> getTransformedSize();
    /**
     * Sets the size. Should be used instead of SFML's setSize.
     */
    void setTransformedSize(TransformedVector<> newSize);

    /**
     * Gets the position as a TransformedVector.
     */
    TransformedVector<> getTransformedPosition();
    /**
     * Sets the position. Should be used instead of SFML's setPosition.
     */
    void setTransformedPosition(TransformedVector<> newPosition);

    void changeTexture(std::string texturePath);
};

#endif
