#include "tech.h"

#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

Tech::Tech(std::string path, short newLevel, ParentsVector newParents, bool newStraightLine)
          : parents(newParents){
    researched = false;
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
        intelligenceGain = data["intelligenceGain"];
        duration = data["duration"];

        cost = { data["cost"]["food"],data["cost"]["materials"],data["cost"]["capacity"] };

        statBoosts = {
            {
                data["statBoosts"]["addends"]["huntBonus"],
                data["statBoosts"]["addends"]["gatheringBonus"],
                data["statBoosts"]["addends"]["fitnessGain"],
            }
        };

    } else {
        throw std::runtime_error("Could not open file at " + path);
    }

    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    button = new Button(100, 0, "assets/techtree/res-"+lowerName+".png", nullptr);

    researchedBox = new Rectangle(0, 0, "assets/researched.png");
}

Tech::~Tech() {
    delete button;
    delete researchedBox;
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

Rectangle& Tech::getResearchedBox() {
    return *researchedBox;
}

short Tech::getLevel() {
    return level;
}

void Tech::setLevel(short newLevel) {
    level = newLevel;
}

short Tech::getIntelligenceGain() {
    return intelligenceGain;
}

Tech::StatBoosts Tech::getBonuses() {
    return statBoosts;
}

std::string Tech::getDescription() {
    return description;
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

bool Tech::isResearched() {
    return researched;
}

void Tech::setResearched(bool newResearched) {
    researched = newResearched;
    if (researched) {
        researchedBox->setTransformedSize({24, 24});
    } else {
        researchedBox->setTransformedSize({0, 0});
    }
}

int Tech::getRequiredIntelligence() {
    return requiredIntelligence;
}

short Tech::getDuration() {
    return duration;
}

Resources Tech::getCost() {
    return cost;
}

void Tech::updateButtonState() {
    if (!researched) {
        button->setClickability(true);
    }
    else {
        button->setClickability(false);
        //TODO: change Texture from disabled to green highlighted
    }

    for (auto& it : parents) {
        if (it == nullptr) {
            return;
        }
        if (!it->isResearched()) {
            button->setClickability(false);
            break;
        }
    }
}
