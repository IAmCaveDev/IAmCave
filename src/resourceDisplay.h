#ifndef RESOURCEDISPLAY_H
#define RESOURCEDISPLAY_H

#include "textbox.h"
#include <SFML/Graphics.hpp>
#include "game.h"
#include "gamestate.h"

#include <random>
#include "action.h"
class resourceDisplay
{
public:
	resourceDisplay() = delete;
	explicit resourceDisplay(Game& gameRef);
	~resourceDisplay();

	std::vector<Textbox*> textBoxes;
	std::vector<Textbox*> resourceDisplay::getResources();
	std::vector<Rectangle*> resourceDisplay::getHeaps();

	sf::Texture resourceDisplay::getFoodTexture();
	sf::Texture resourceDisplay::getMaterialsTexture();

	std::vector<Textbox*> resources;
	std::vector<Rectangle*> heaps;



	Game& gamereference;

private:
	Textbox* food;
	Textbox* materials;
	Textbox* space;

	Rectangle* foodHeap;
	Rectangle* materialsHeap;


	sf::Texture* textureMeat;
	sf::Texture* textureStones;
};
#endif;
