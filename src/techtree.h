#ifndef TECHTREE_H
#define TECHTREE_H

#include <map>
#include <memory>
#include <string>

#include "json.hpp"
using json = nlohmann::json;

#include "tech.h"

class Techtree {
private:
    std::map<std::string, std::shared_ptr<Tech>> tree;

    TransformedVector<> size;
    TransformedVector<> pos;

    std::vector<short> sizePerLevel;
    std::vector<short> iteratorPerLevel;

    int techSize = 100;
    int padding = 200;

    void positionTree(json data, short level, TransformedVector<> lastPos);
    void parse(std::shared_ptr<Tech> parent, json data, short level);

public:
    Techtree(std::string path, TransformedVector<> newSize,
             TransformedVector<> newPos);

    void display(sf::RenderWindow& win);

    void onResize();
};

#endif
