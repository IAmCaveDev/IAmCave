#ifndef TECHTREE_H
#define TECHTREE_H

#include <vector>

#include "json.hpp"
#include "tech.h"

class Techtree {
private:
    std::vector<Tech> Tree;
public:
    Techtree();
};

#endif