#include "caveman.h"

#include <random>
#include <vector>

short Caveman::counter = 0;

std::vector<std::string> femaleNames = {
    "Hillary",
    "Liz",
    "Gina",
    "Chelsea",
    "Luna",
    "Giny",
    "Selina",
    "Lillian",
    "Harleen"
};

std::vector<std::string> maleNames = {
    "Donald",
    "Bernie",
    "Harambe",
    "Gabe",
    "Matthew",
    "Harry",
    "Ron",
    "Oswald",
    "Bruce"
};

std::vector<std::string> femaleTextures = {
    "assets/cavewoman.png",
    "assets/cavewoman2.png",
    "assets/cavewoman3.png"
};

std::vector<std::string> maleTextures = {
    "assets/caveman.png",
    "assets/caveman1.png",
    "assets/caveman2.png"
};


//Constructor
Caveman::Caveman(int maxAge, int minAge) : id(counter){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> unid(minAge, maxAge);

    age = unid(rng);


    std::uniform_int_distribution<int> unbd(0, 1);

    if(counter < 3){
        male = true;
    }else if(counter < 5){
        male = false;
    }else{
        male = (unbd(rng) != 0);
    }

    std::uniform_int_distribution<int> maleN(0, maleNames.size() - 1);
    std::uniform_int_distribution<int> femaleN(0, femaleNames.size() - 1);

    if(male){
        name = maleNames[maleN(rng)];
    }else{
        name = femaleNames[femaleN(rng)];
    }


    std::uniform_int_distribution<int> stats(1, 5);

    fitness = stats(rng);
    intelligence = stats(rng);

    std::uniform_int_distribution<int> maleT(0, maleTextures.size() - 1);
    std::uniform_int_distribution<int> femaleT(0, femaleTextures.size() - 1);

    if (male) {
        texPath = maleTextures[maleT(rng)];
    }else{
        texPath = femaleTextures[femaleT(rng)];
    }

    button = new Button({100, 200}, {0, 0}, texPath,
        nullptr, std::bind(&ButtonFunctions::Tribe::displayInfo, std::ref(*this)));

    infobox = new Textbox({200, 200}, {450, 400}, "assets/info.png", "TEST");

    counter += 1;
}


//Destructor
Caveman::~Caveman() {
    delete button;
}


//Getter

short Caveman::getId(){
	return id;
}
std::string Caveman::getName(){
	return name;
}

short Caveman::getFitness(){
	return fitness;
}

unsigned short Caveman::getAge(){
	return age;
}

short Caveman::getIntelligence(){
	return intelligence;
}

Button& Caveman::getButton() {
	return *button;
}
Textbox& Caveman::getInfobox() {
	return *infobox;
}

EActions Caveman::getCurrentAction(){
	return currentAction;
}

bool Caveman::isMale(){
	return male;
}

bool Caveman::isPregnant() {
	return isPregnant;
}

//Setter

void Caveman::setFitness(short newFit) {
	fitness = newFit;
}

void Caveman::setInfoboxVisible(bool visible){
    infoboxVisible = visible;
}

void Caveman::setPosition(TransformedVector<> newPosition){
    button->setTransformedPosition(newPosition);
    infobox->setTransformedPosition(
        {newPosition.getRealX() - infobox->getTransformedSize().getRealX(),
         newPosition.getRealY() - infobox->getTransformedSize().getRealY()});
}

void Caveman::setCurrentAction(EActions newOccupation) {
    currentAction = newOccupation;
}

void Caveman::setPregnancy(bool newPregnant) {

	//Return if unit is already pregnant
	if (isPregnant)
		return;

	this->isPregnant = newPregnant;

	//Dynamic pregnancy times
	preg_counter = std::rand() % 2 + 8;
}


//Working Functions

//Recalculate size and position of unit after window resize
void Caveman::onResize(){
    button->setPosition(button->getTransformedPosition());
    button->setSize(button->getTransformedSize());
    infobox->setPosition(infobox->getTransformedPosition());
    infobox->setSize(infobox->getTransformedSize());
}


void Caveman::display(sf::RenderWindow& win) const {
    win.draw(*button);
    if(infoboxVisible){
        win.draw(*infobox);
    }
}
