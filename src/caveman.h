#ifndef CAVEMAN_H
#define CAVEMAN_H

#define MIN_ADULT_AGE 3

#include <string>

#include "action.h"
#include "button.h"
#include "buttonfunctions.h"

//Working class for the player units
class Caveman {
private:

	// UNIT STATS
	short fitness;				//Hunting ability
    short intelligence;			//Research ability
	bool male;					//Gender variable; 1 for male, 0 for female
	const short id;				//Unique Unit ID
	unsigned short age;			//Current Age
	short preg_counter = -1;	//Pregnancy counter
	bool isPregnant = false;	//Pregnancy active or not
	std::string name;			//Unit name string
	

	EActions currentAction;	//Action which is currently being assigned, caveman won't be able to do anything else while this is set
	static short counter;	//Amount of turns the current action is going to take

    std::string texPath;	//PLACEHOLDER
    Button* button;			//PLACEHOLDER

    bool infoboxVisible = false;	//PLACEHOLDER
    Textbox* infobox;				//PLACEHOLDER


public:

	//Constructor
    explicit Caveman(int maxAge, int minAge);

	//Destructor
    ~Caveman();


//Getters
public:

	short getId();

    std::string getName();

	short getFitness();

	unsigned short getAge();

	short getIntelligence();

	Button& getButton();

	Textbox& getInfobox();

	EActions getCurrentAction();

	bool isMale();

	bool isPregnant();


//Setters
public:

	void setFitness(short newFit);

	void setInfoboxVisible(bool visible);

	void setPosition(TransformedVector<> newPosition);

	void setCurrentAction(EActions newOccupation);

	void setPregnancy(bool newPregnant);

//Working Functions
public:

    void onResize();

    void display(sf::RenderWindow& win) const;


//External Class Access
public:

	friend Action;

};

#endif
