#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#ifndef BUTTON_H
#define BUTTON_H

class Button : public sf::RectangleShape {
private:
	bool clickable;

public:
	Button();
	bool IsClicked(sf::Vector2i& MousePosition);

};

#endif