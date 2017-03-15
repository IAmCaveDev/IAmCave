#ifndef TECH_H
#define TECH_H

#include "enum.h"

class Tech {
private:
    ETechs type;
    Tech& parent;
    bool isResearched;

public:
    Tech(ETechs type);
};

#endif
