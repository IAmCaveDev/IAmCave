#include "resourceDisplay.h"
#include "game.h"
#include <sstream>
resourceDisplay::resourceDisplay()
{



}

std::vector<Textbox*> resourceDisplay::getResources(Game& game)
{
	
	
	food = new Textbox({ 450, 150 }, { 400, 0 }, "assets/resource-column.png", "Meat: " + std::to_string(int(game.getResources().food)), 5, 30);
	materials = new Textbox({ 450, 150 }, { 600, 0 }, "assets/resource-column.png", "Stones: " + std::to_string(game.getResources().buildingMaterial), 5, 30);
	space = new Textbox({ 450, 150 }, { 800, 0 }, "assets/resource-column.png", "Beds: " +  std::to_string(game.getResources().cavemanCapacity), 5, 30);
	
	textBoxes.clear();
	textBoxes.push_back(food);
	textBoxes.push_back(materials);
	textBoxes.push_back(space);

	return textBoxes;

}
resourceDisplay::~resourceDisplay()
{

}
