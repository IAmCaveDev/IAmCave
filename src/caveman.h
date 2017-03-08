#ifndef CAVEMAN_H
#define CAVEMAN_H

#define MIN_ADULT_AGE 3

#include <string>

#include "action.h"
#include "button.h"


class Caveman {
private:

    /** VARIABLES */
    short fitness;
    short intelligence;
	virtual const bool male;
	const short id;
	unsigned short age;
	short preg_counter = -1;
	bool isPregnant = false;
	std::string name;
	EActions currentAction;
	static short counter;
    std::string texturePath;
    Button* button;			
    bool infoboxVisible = false;	
    Textbox* infobox;				

    /** CONSTRUCTOR */
    explicit Caveman() = 0;

	/** DESTRUCTOR */
    ~Caveman();

    /** FUNCTIONS */
    void onResize();
    void display(sf::RenderWindow& win) const;

    /** GETTERS */
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

    /** SETTERS */
    void setFitness(short newFit);
    void setInfoboxVisible(bool visible);
    void setPosition(TransformedVector<> newPosition);
    void setCurrentAction(EActions newOccupation);
    void setPregnancy(bool newPregnant);

	friend Action;

};


class Female : public Caveman {
private:
    bool male = false;

    std::vector<std::string> textures = {
        "assets/cavewoman.png",
        "assets/cavewoman2.png",
        "assets/cavewoman3.png"
    };
    std::vector<std::string> names = {
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

public:
    /** CONSTRUCTOR */
    Female();
};


class Male : Caveman {
private:
    bool male = true;

    std::vector<std::string> textures = {
        "assets/caveman.png",
        "assets/caveman1.png",
        "assets/caveman2.png"
    };
    std::vector<std::string> names = {
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

public:
    /** CONSTRUCTOR */
    Male();
};

#endif
