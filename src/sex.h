#ifndef SEX_H
#define SEX_H

#include <vector>
#include <string>
#include "action.h"
#include "female.h"

class Sex : public Action {
public:
    /**
    * Create sex action.
    * Action duration is a fixed variable for this action type.
    */
    Sex();

    void addActor(std::shared_ptr<Caveman> actor);
    ActionPackage resolve(Tech::StatBoosts bonuses);
};

#endif
