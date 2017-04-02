#include "resourceDisplay.h"
#include "game.h"
#include <sstream>

resourceDisplay::resourceDisplay(Game& gameref) : gamereference (gameref) {
	food = new Textbox({ 450, 150 }, { 400, 0 }, "assets/resource-column.png", "Meat: " + std::to_string(int(gameref.getResources().food)), 5, 30);
	materials = new Textbox({ 450, 150 }, { 600, 0 }, "assets/resource-column.png", "Stones: " + std::to_string(gameref.getResources().buildingMaterial), 5, 30);
	space = new Textbox({ 450, 150 }, { 800, 0 }, "assets/resource-column.png", "Beds: " + std::to_string(gameref.getResources().cavemanCapacity), 5, 30);

	foodHeap = new Rectangle({ 200, 400 }, { 1223, 160 }, "assets/heaps/meat-l.png");
	materialsHeap = new Rectangle({ 400, 800 }, { 1400, 138 }, "assets/heaps/stones-l.png");
	grass = new Rectangle({ 2160, 70 }, { 0, 900 }, "assets/cave-grass.png");
	//gamereference = new gameref();

	textureMeat = new sf::Texture;
	textureStones = new sf::Texture;
	plainTextBox = new sf::Texture;
	plainTextBox->loadFromFile("assets/resource-column.png");
}



std::vector<Textbox*>& resourceDisplay::getResources() {
	food->setText("Meat: " + std::to_string(int(gamereference.getResources().food)));
	materials->setText("Stones: " + std::to_string(gamereference.getResources().buildingMaterial));
	space->setText("Beds: " + std::to_string(gamereference.getResources().cavemanCapacity));
	
	textBoxes.clear();
	textBoxes.empty();
	textBoxes.push_back(food);
	textBoxes.push_back(materials);
	textBoxes.push_back(space);

	return textBoxes;
}

std::vector<Rectangle*>& resourceDisplay::getHeaps() {
	if (gamereference.getResources().food > 50){
		textureMeat->loadFromFile("assets/heaps/meat-l.png");
	}
	else if (gamereference.getResources().food > 25){
		textureMeat->loadFromFile("assets/heaps/meat-m.png");
	}
	else{
		textureMeat->loadFromFile("assets/heaps/meat-s.png");
	}

	if (gamereference.getResources().buildingMaterial > 50){
		textureStones->loadFromFile("assets/heaps/stones-l.png");
	}
	else if (gamereference.getResources().buildingMaterial > 25){
		textureStones->loadFromFile("assets/heaps/stones-m.png");
	}
	else{
		textureStones->loadFromFile("assets/heaps/stones-s.png");
	}

	foodHeap->setTexture(textureMeat);
	materialsHeap->setTexture(textureStones);

	heaps.clear();

	heaps.push_back(foodHeap);
	heaps.push_back(materialsHeap);

	return heaps;
}



sf::Texture& resourceDisplay::getFoodTexture() {
	if (gamereference.getResources().food > 50){
		textureMeat->loadFromFile("assets/heaps/meat-l.png");
	}
	else if (gamereference.getResources().food > 25){
		textureMeat->loadFromFile("assets/heaps/meat-m.png");
	}
	else{
		textureMeat->loadFromFile("assets/heaps/meat-s.png");
	}
	return *textureMeat;
}

sf::Texture& resourceDisplay::getMaterialsTexture() {
	if (gamereference.getResources().food > 50){
		textureStones->loadFromFile("assets/heaps/stones-l.png");
	}
	else if (gamereference.getResources().food > 25){
		textureStones->loadFromFile("assets/heaps/stones-m.png");
	}
	else{
		textureStones->loadFromFile("assets/heaps/stones-s.png");
	}

	return *textureStones;
}

Rectangle & resourceDisplay::getGrassTexture() {
	return *grass;
}

Rectangle & resourceDisplay::getFirePlace() {
	return *grass; //TODO
}




resourceDisplay::~resourceDisplay() {
	delete food;
	delete materials;
	delete space;
	}
