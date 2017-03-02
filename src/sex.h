#ifndef SEX_H
#define SEX_H

#include <vector>
#include <string>
#include "action.h"
#include "game.h"

class Sex : public Action {

private:


//Constructor
public:
	Sex(short duration, Game& gameRef);


//Working Functions
public:

	//Add Unit(Caveman) to this action
	void addActor(Caveman* actor);

	//Calculate results for this action
	void resolve();
};

#endif