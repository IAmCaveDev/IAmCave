#ifndef TECH_H
#define TECH_H

#include <memory>
#include <vector>

#include "button.h"
#include "resources.h"

/**
 * A researchable technology.
 */
class Tech {
public:
    /**
     * The bonuses a technology provides when researched.
     */
    struct StatBoosts {
        struct {
            float huntBonus;
            float gatheringBonus;
            float fitnessGain;
            float passiveIntGain;
            float buildingBonus;
            float birthGain;
        } addends;
        struct {
            float example;
        } multipliers;

        StatBoosts operator+(const StatBoosts& other) const {
            return StatBoosts({
                {
                    addends.huntBonus + other.addends.huntBonus,
                    addends.gatheringBonus + other.addends.gatheringBonus,
                    addends.fitnessGain + other.addends.fitnessGain,
                    addends.passiveIntGain + other.addends.passiveIntGain,
                    addends.buildingBonus + other.addends.buildingBonus,
                    addends.birthGain + other.addends.birthGain
                },
                {
                    multipliers.example + other.multipliers.example - 1
                }});
        }
    };

private:
    typedef std::vector<std::shared_ptr<Tech>> ParentsVector;
    struct ArrowsToParents {
        sf::VertexArray tip;
        std::vector<sf::VertexArray> lines;
    } arrowsToParents;

    short level;

    ParentsVector parents;

    std::string name;
    std::string description;
    std::string iconPath;
    int requiredIntelligence;
    Resources cost;
    StatBoosts statBoosts;
    short intelligenceGain;
    short duration;

    bool researched;

    Button* button;
    Rectangle* researchedBox;

public:
    bool straightLine;

    /**
     * Constructs a new Tech.
     * @param path The path to the tech JSON file
     * @param newLevel The level in the Techtree the Tech is in
     * @param newParents A list of parents
     * @param newStraightLine The lines generated to this Tech's children will
     * be straight if true.
     */
    Tech(std::string path, short newLevel, ParentsVector newParents,
         bool newStraightLine = false);

    ~Tech();

    std::string getName();
    /**
     * @return A reference to the list of parents.
     */
    ParentsVector& getParents();

    /**
     * @return A reference to the Tech's button.
     */
    Button& getButton();

    Rectangle& getResearchedBox();

    /**
     * @return The level of the Tech in the Techtree.
     */
    short getLevel();
    /**
     * Sets the level of the Tech in the Techtree.
     */
    void setLevel(short newLevel);
    /**
     * @return Intelligence the researching caveman gains.
     */
    short getIntelligenceGain();
    /**
     * @return Bonuses the Tech gives when it is researched.
     */
    StatBoosts getBonuses();
    /**
     * @return The Tech description as written in the json file.
     */
    std::string getDescription();
    /**
     * Creates Arrows as SFML VertexArrays to display between Techs in tree.
     */
    void createArrowsToParents();
    /**
     * Clears all Arrows and calls createArrowsToParents() again. Needed on resize.
     */
    void updateArrowsToParents();
    /**
     * Helper function for createArrowsToParents()
     */
    TransformedVector<> getRightArrowNode();
    /**
     * Helper function for createArrowsToParents()
     */
    TransformedVector<> getLeftArrowNode();
    /**
     * Returns a Reference to the Arrows to Parents in tree. Mainly needed to draw the arrows
     * in techtree.display() function.
     */
    ArrowsToParents getArrowsToParents();
    /**
     * @return if Tech is already researched.
     */
    bool isResearched();
    /**
     * Sets if the Tech is researched or not.
     */
    void setResearched(bool newResearched);
    /**
     * @return required intelligence to research Tech
     */
    int getRequiredIntelligence();
    /**
     * @return the duration of the Tech.
     */
    short getDuration();
    /*
     * @return the cost of the Tech
     */
    Resources getCost();
    /**
     * Enable or disable the Tech button, depending on wether the parents are researched and
     * wether the Tech itself is already researched.
     */
    void updateButtonState();
};

#endif
