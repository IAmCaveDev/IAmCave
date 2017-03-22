#ifndef TECHTREE_H
#define TECHTREE_H

#include <map>
#include <memory>
#include <string>

#include "json.hpp"
using json = nlohmann::json;

#include "rectangle.h"
#include "tech.h"

/**
 * Constructs, stores and positions Techs.
 */
class Techtree : public Rectangle {
private:
    std::map<std::string, std::shared_ptr<Tech>> tree;

    std::vector<short> sizePerLevel;
    std::vector<short> iteratorPerLevel;

    int techSize = 100;
    int padding = 200;

    bool visibility;

    /**
     * Positions the Techs according to the tree's structure.
     */
    void positionTree(json data, short level, TransformedVector<> lastPos);
    /**
     * Parses the json data and constructs new Techs.
     */
    void parse(std::shared_ptr<Tech> parent, json data, short level);

public:
    /**
     * Constructs a Techtree and it's Techs.
     * @param backgroundPath The image to use as a background.
     * @param path The path to a json file to load the Techtree data from.
     * @param newSize The display size of the Techtree.
     * @param newPos The display position of the Techtree.
     */
    Techtree(std::string backgroundPath, std::string path,
             TransformedVector<> newSize, TransformedVector<> newPos);

    /**
     * Sets the visiblity of the Techtree.
     */
    void setVisibility(bool newVisibility);

    /**
     * Displays the Techtree and it's Techs.
     */
    void display(sf::RenderWindow& win);

    /**
     * Resizes and repositions all Techs in the Techtree.
     */
    void onResize();
};

#endif
