#ifndef THINK_H
#define THINK_H

#include <vector>
#include <string>
#include "action.h"
#include "techtree.h"

class Think : public Action {
private:
	ETechs tech;

public:
    Think(ETechs newtech, short time);

    void addActor(std::shared_ptr<Caveman> actor);
    ActionPackage resolve();
	
    ETechs getTech();
};

#endif
