#ifndef TECHTREE_H
#define TECHTREE_H

#include <set>
#include <memory>
#include <string>

#include "json.hpp"
using json = nlohmann::json;

#include "tech.h"

class Techtree {
private:
    std::set<std::shared_ptr<Tech>> tree;

    TransformedVector<> size;
    TransformedVector<> pos;

    int techSize = 100;
    int padding = 200;

    void parse(std::shared_ptr<Tech> parent, json data,
               TransformedVector<> pos);

public:
    Techtree(std::string path, TransformedVector<> newSize,
             TransformedVector<> newPos);

    void display(sf::RenderWindow& win);
};

#endif
