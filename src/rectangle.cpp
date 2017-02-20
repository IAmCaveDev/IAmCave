#include "rectangle.h"

Rectangle::Rectangle(const TransformedVector<>& size,
                     const TransformedVector<>& position,
                     std::string texturePath) : sf::RectangleShape(size){
    tex.loadFromFile(texturePath);
    setTexture(&tex);
    setPosition(position);

    transformedSize = size;
    transformedPosition = position;
}

TransformedVector<> Rectangle::getTransformedSize(){
    return transformedSize;
}
void Rectangle::setTransformedSize(TransformedVector<> newPosition){

}

TransformedVector<> Rectangle::getTransformedPosition(){
    return transformedPosition;
}
void Rectangle::setTransformedPosition(TransformedVector<> newPosition){

}
