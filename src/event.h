#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <fstream>
#include <memory>

#include "enum.h"
#include "json.hpp"
#include "cavemanfactory.h"
using json = nlohmann::json;

class Event {
private:
    /**
    * Requirements for the event to trigger
    */
    struct Trigger {
        ETechs has_tech;
        ETechs missing_tech;
        int tribeSize;
        float tribeFood;
        int tribeMaterial;
    };
    /**
    * A list of possible effects created by the event
    */
public:
    struct Effects {
        /**
        * General effects affecting the entire game
        */
        float huntBonus;
        float gatheringBonus;
        float fitnessGain;
        float intelligenceGain;
        int capacityGain;
        float foodGain;
        int materialGain;

        /** 
        * Stats for new caveman if created by the event
        */
        unsigned short new_age;
        short new_intelligence;
        short new_fitness;
        bool new_isMale;
    };

    /**
    * Content and effects for choosable options by the player
    */
    struct Option {
        std::string name;
        Effects effects;
        Button* button;
    };
private:

    short id;
    std::string title;
    std::string description;
    Trigger trigger;
    std::vector<std::shared_ptr<Option>> options;
    Textbox* textbox;

public:

    Event(const std::string path);
    ~Event();

    Trigger getTrigger() const;
    std::vector<std::shared_ptr<Option>> getOptions() const;
    Textbox* getTextBox() const;
    short getID() const;
    std::string getDescription() const;
};

#endif