#ifndef CAVEMAN_H
#define CAVEMAN_H

#define MIN_ADULT_AGE 3

#include <string>

#include "action.h"
#include "button.h"

class Caveman {
private:
    static short counter;

    const short id;
    std::string name;

    bool male;
    unsigned short age;

    EActions currentAction;

    short fitness;
    short intelligence;

    std::string texPath;

    Button* button;

    bool infoboxVisible = false;
    Textbox* infobox;

public:
    explicit Caveman(int maxAge, int minAge);
    ~Caveman();

    void setInfoboxVisible(bool visible);

    short getId();
    std::string getName();
    bool isMale();
    unsigned short getAge();
    short getFitness();
    void setFitness(short newFit);
    short getIntelligence();

    Button& getButton();
    Textbox& getInfobox();

    void setPosition(TransformedVector<> newPosition);

    EActions getCurrentAction();
    void setCurrentAction(EActions newOccupation);

    void onResize();

    void display(sf::RenderWindow& win) const;

    friend Action;
};

#endif
