#ifndef TECH_H
#define TECH_H

#include <memory>
#include <vector>

class Tech {
private:
    typedef std::vector<std::shared_ptr<Tech>> ParentsVector;
    struct StatBoosts {
        float huntBonus;
        float gatheringBonus;
        float fitnessGain;
        float intelligenceGain;
    };

    ParentsVector parents;

    std::string name;
    std::string description;
    std::string iconPath;

    int requiredIntelligence;

    StatBoosts statBoosts;


public:
    Tech(std::string path, ParentsVector newParents);

    ParentsVector& getParents();
};

#endif
