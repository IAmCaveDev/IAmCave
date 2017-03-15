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
    std::set<std::unique_ptr<Tech>> tree;

    void parse(const std::unique_ptr<Tech>& parent, json data);

public:
    Techtree(std::string path);
};

#endif
