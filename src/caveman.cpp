#include "caveman.h"

short Caveman::counter = 0;

Caveman::Caveman() : id(counter) {

}
Caveman::~Caveman() {
    delete button;
}

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
