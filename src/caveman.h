#ifndef CAVEMAN_H
#define CAVEMAN_H

#include <string>

#include "action.h"
#include "button.h"
#include "buttonfunctions.h"

class Caveman {
private:
    static short counter;

    const short id;
    std::string name;

    bool male;
    unsigned short age;

    bool idle;

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
    short getIntelligence();

    Button& getButton();
    Textbox& getInfobox();

    void setPosition(TransformedVector<> newPosition);

    void onResize();

    void display(sf::RenderWindow& win) const;

    friend Action;
};

#endif
