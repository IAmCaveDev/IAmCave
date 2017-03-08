#ifndef HUNT_H
#define HUNT_H

#include <vector>
#include <string>
#include "action.h"

class Hunt : public Action {

private:

	bool easy;	//Difficulty of the hunt


	//Constructor
public:
<<<<<<< HEAD
	Hunt(bool easy, short duration, Game& gameRef);

=======
    Hunt(EActions newtype, short duration);
>>>>>>> refs/remotes/origin/master

	//Working Functions
public:

	//Add Unit(Caveman) to the actors vector
	void addActor(Caveman* actor);

	//Calculate results for this action
	void resolve();
};


#endif