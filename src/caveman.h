#ifndef CAVEMAN_H
#define CAVEMAN_H

#define MIN_ADULT_AGE 3

#include <string>
#include <memory>

#include "enum.h"
#include "button.h"

class Caveman : public std::enable_shared_from_this<Caveman> {
private:
    static short counter;

    const short id;

    unsigned short age;

    EActions currentAction;

    short fitness;
    short intelligence;

    bool infoboxVisible = false;
    Textbox* infobox;

protected:
    std::string name;

    std::string texPath;
    Button* button;

public:
    Caveman(int maxAge, int minAge);
    ~Caveman();

    void setInfoboxVisible(bool visible);

    short getId();
    std::string getName();
    virtual bool isMale() = 0;
    unsigned short getAge();
    short getFitness();
    void setFitness(short newFit);
    short getIntelligence();

    Button& getButton();
    Textbox& getInfobox();

    void initButton();

    void setPosition(TransformedVector<> newPosition);

    EActions getCurrentAction();
    void setCurrentAction(EActions newOccupation);

    void onResize();

    void display(sf::RenderWindow& win) const;

};

#endif
