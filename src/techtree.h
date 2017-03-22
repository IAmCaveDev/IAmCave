#ifndef TECHTREE_H
#define TECHTREE_H

#include <map>
#include <memory>
#include <string>

#include "json.hpp"
using json = nlohmann::json;

#include "rectangle.h"
#include "tech.h"

class Techtree : public Rectangle {
private:
    std::map<std::string, std::shared_ptr<Tech>> tree;

    std::vector<short> sizePerLevel;
    std::vector<short> iteratorPerLevel;

    int techSize = 100;
    int padding = 200;

    bool visibility;

    void positionTree(json data, short level, TransformedVector<> lastPos);
    void parse(std::shared_ptr<Tech> parent, json data, short level);

public:
    Techtree(std::string backgroundPath, std::string path,
             TransformedVector<> newSize, TransformedVector<> newPos);

    void setVisibility(bool newVisibility);

    void display(sf::RenderWindow& win);

    void onResize();
};

#endif
