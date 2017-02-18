#include "button.h"

Button::Button(const sf::Vector2f& size, std::string texturePath, const sf::Vector2f& newposition, std::function<void()> newcallback) : sf::RectangleShape(size){
	texture.loadFromFile(texturePath);
	setTexture(texture);
	setPosition(newposition);
	callback = newcallback;
	clickable = true;
}

bool Button::isClicked(sf::Vector2i& mousePosition){
	if (clickable == false) return false;
	sf::Vector2i myPosition = sf::Vector2i(getPosition());
	if ((mousePosition.x >= myPosition.x) && (mousePosition.x <= myPosition.x + getSize().x) && (mousePosition.y >= myPosition.y) && (mousePosition.y <= myPosition.y + getSize().y)){
		callback();
		return true;
	}
	return false;
}
