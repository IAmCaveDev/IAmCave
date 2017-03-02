#ifndef HUNT_H
#define HUNT_H

#include <vector>
#include <string>
#include "action.h"
#include "game.h"

class Hunt : public Action {

private:

	bool easy;	//Difficulty of the hunt


	//Constructor
public:
	Hunt(bool easy, short duration, Game& gameRef);


	//Working Functions
public:

	//Add Unit(Caveman) to the actors vector
	void addActor(Caveman* actor);

	//Calculate results for this action
	void resolve();
};


#endif