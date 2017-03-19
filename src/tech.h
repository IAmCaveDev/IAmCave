#ifndef TECH_H
#define TECH_H

#include <memory>
#include <vector>

#include "button.h"

class Tech {
private:
    typedef std::vector<std::shared_ptr<Tech>> ParentsVector;
    struct StatBoosts {
        float huntBonus;
        float gatheringBonus;
        float fitnessGain;
        float intelligenceGain;
    };

    short level;

    ParentsVector parents;

    std::string name;
    std::string description;
    std::string iconPath;
    int requiredIntelligence;
    StatBoosts statBoosts;

    Button button;

public:
    Tech(std::string path, short newLevel, ParentsVector newParents);

    ParentsVector& getParents();

    Button& getButton();

    short getLevel();
    void setLevel(short newLevel);
};

#endif
