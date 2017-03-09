#ifndef CAVEMAN_H
#define CAVEMAN_H

#define MIN_ADULT_AGE 3

#include <string>
#include <random>
#include <vector>

#include "buttonfunctions.h"
#include "action.h"
#include "button.h"


class Caveman {
private:
    const short id;

protected:
    short fitness;
    short intelligence;
    bool male;
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

public:
    explicit Caveman();
    ~Caveman();

    void onResize();
    void display(sf::RenderWindow& win) const;

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

    void setFitness(short newFit);
    void setInfoboxVisible(bool visible);
    void setPosition(TransformedVector<> newPosition);
    void setCurrentAction(EActions newOccupation);
    void setPregnancy(bool newPregnant);

	friend Action;

};

#endif