#ifndef RESOURCEDISPLAY_H
#define RESOURCEDISPLAY_H

#include "textbox.h"
#include <SFML/graphics.hpp>
#include "game.h"
#include "gamestate.h"

#include <random>
#include "action.h"
class resourceDisplay
{
public:
	resourceDisplay();
	~resourceDisplay();
	Textbox* food;
	Textbox* materials;
	Textbox* space;
	std::vector<Textbox*> textBoxes;
	std::vector<Textbox*> resourceDisplay::getResources(Game& game);
	std::vector<Textbox>* resources;

private:
};
#endif;
