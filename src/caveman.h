#ifndef CAVEMAN_H
#define CAVEMAN_H

#define MIN_ADULT_AGE 0

#include <string>
#include <memory>

#include "enum.h"
#include "button.h"

/**
 * A Caveman. Can perform actions.
 */
class Caveman : public std::enable_shared_from_this<Caveman> {
private:
    /**
     * Counter for generating unique IDs.
     */
    static short counter;

    const short id;

    unsigned short age;

    EActions currentAction;

    short fitness;
    short intelligence;

    bool infoboxVisible = false;
    /**
     * Textbox to display the caveman's stats.
     */
    Textbox* infobox;
    /**
     * Marker that pops up when the caveman is selected for an action.
     */
    Button* actionbox;

protected:
    std::string name;

    std::string texPath;
    Button* button;

public:
    /**
     * Constructs a Caveman.
     */
    Caveman(int maxAge, int minAge);
    /**
     * Deletes the button,infobox and actionbox.
     */
    ~Caveman();

    void setInfoboxVisible(bool visible);

    short getId();
    std::string getName();
    virtual bool isMale() = 0;
    unsigned short getAge();
    void aging();
    short getFitness();
    void setFitness(short newFit);
    short getIntelligence();
    void setIntelligence(short newInt);
    void addIntelligence(short newInt);

    Button& getButton();
    Textbox& getInfobox();
    /**
     * Initiliazes the button and sets its alternate Callback to display the Infobox.
     */
    void initButton();
    /**
     * Moves the button, infobox and actionbox.
     */
    void setPosition(TransformedVector<> newPosition);
    /**
     * Calls setSize() of the button.
     */
    void setSize(TransformedVector<> newSize);

    EActions getCurrentAction();
    void setCurrentAction(EActions newOccupation);

    /**
     * Set Action Box to display a specific Marker for each actiontype
     * At the moment: only one marker avaiable.
     *@param displayedAction Type of the action/marker, idle means no marker is shown.
     */
    void setActionBox(EActions displayedAction);
    /**
     * Resizes and Repositions button, infobox and actionbox.
     */
    void onResize();
    /**
     * Draw the caveman, also the info- and actionbox if their conditions are met.
     */
    void display(sf::RenderWindow& win) const;

};

#endif
