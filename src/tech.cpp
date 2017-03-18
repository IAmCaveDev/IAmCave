#include "tech.h"

#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

Tech::Tech(std::string path, ParentsVector newParents)
          : parents(newParents), button(100, 0, "assets/techplaceholder.png", nullptr) {
    std::ifstream in(path);
    if (in.good()) {
        json data;
        in >> data;

        name = data["name"];
        description = data["description"];
        iconPath = data["iconPath"];

        requiredIntelligence = data["requiredIntelligence"];

        statBoosts = {
            data["statBoosts"]["huntBonus"],
            data["statBoosts"]["gatheringBonus"],
            data["statBoosts"]["fitnessGain"],
            data["statBoosts"]["intelligenceGain"],
        };

    } else {
        throw std::runtime_error("Could not open file at " + path);
    }
}

Tech::ParentsVector& Tech::getParents() {
    return parents;
}

Button& Tech::getButton() {
    return button;
}
