#ifndef SEX_H
#define SEX_H

#include <vector>
#include <string>
#include "action.h"
#include "game.h"

class Sex : public Action {

private:

public:
    Sex(EActions newtype, short time);

public:
	void addActor(Caveman* actor);
	void resolve();
};

#endif