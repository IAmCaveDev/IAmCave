#include "tech.h"

#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

Tech::Tech(std::string path, short newLevel, ParentsVector newParents, bool newStraightLine)
          : parents(newParents){
    level = newLevel;
    straightLine = newStraightLine;

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

    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    button = new Button(100, 0, "assets/techtree/res-"+lowerName+".png", nullptr);
}

std::string Tech::getName() {
    return name;
}

Tech::ParentsVector& Tech::getParents() {
    return parents;
}

Button& Tech::getButton() {
    return *button;
}

short Tech::getLevel() {
    return level;
}

void Tech::setLevel(short newLevel) {
    level = newLevel;
}

void Tech::createArrowsToParents() {
    if (parents[0] == nullptr) {
        return;
    }

    arrowsToParents.tip = sf::VertexArray(sf::Triangles, 3);
    arrowsToParents.tip[0].position = getLeftArrowNode();
    arrowsToParents.tip[1].position = getLeftArrowNode()
                                      + TransformedVector<>(-10, -10);
    arrowsToParents.tip[2].position = getLeftArrowNode()
                                      + TransformedVector<>(-10, 10);

    arrowsToParents.tip[0].color = sf::Color::Black;
    arrowsToParents.tip[1].color = sf::Color::Black;
    arrowsToParents.tip[2].color = sf::Color::Black;

    for (auto& parent : parents) {
        TransformedVector<> parentNode = parent->getRightArrowNode();
        TransformedVector<> thisNode  = getLeftArrowNode() - TransformedVector<>(10, 0);
        sf::VertexArray arrowLine;

        if (parent->straightLine) {
            arrowLine = sf::VertexArray(sf::LinesStrip, 2);
            arrowLine[0].position = thisNode;
            arrowLine[1].position = parentNode;

        } else {
            arrowLine = sf::VertexArray(sf::LinesStrip, 4);

            arrowLine[0].position = thisNode;
            arrowLine[1].position = thisNode
                                    + TransformedVector<>((parentNode.getRealX()
                                                          - thisNode.getRealX())
                                                          / 3, 0);
            arrowLine[2].position = parentNode
                                    - TransformedVector<>((parentNode.getRealX()
                                                          - thisNode.getRealX())
                                                          / 3, 0);
            arrowLine[3].position = parentNode;

            arrowLine[2].color = sf::Color::Black;
            arrowLine[3].color = sf::Color::Black;
        }

        arrowLine[0].color = sf::Color::Black;
        arrowLine[1].color = sf::Color::Black;

        arrowsToParents.lines.push_back(arrowLine);
    }
}

void Tech::updateArrowsToParents() {
    arrowsToParents.lines.clear();

    createArrowsToParents();
}

TransformedVector<> Tech::getRightArrowNode() {
    TransformedVector<> buttonPos = button->getTransformedPosition();
    TransformedVector<> buttonSize = button->getTransformedSize();
    // 10: image padding, 280: image size
    return {buttonPos.getRealX() + buttonSize.getRealX() - static_cast<int>(10.f/280.f * buttonSize.getRealX()),
            buttonPos.getRealY() + buttonSize.getRealY() / 2};
}

TransformedVector<> Tech::getLeftArrowNode() {
    TransformedVector<> buttonPos = button->getTransformedPosition();
    TransformedVector<> buttonSize = button->getTransformedSize();
    // 10: image padding, 280: image size
    return {buttonPos.getRealX() + static_cast<int>(10.f/280.f * buttonSize.getRealX()),
            buttonPos.getRealY() + buttonSize.getRealY() / 2};
}

Tech::ArrowsToParents Tech::getArrowsToParents() {
    return arrowsToParents;
}
