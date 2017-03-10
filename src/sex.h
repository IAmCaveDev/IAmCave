#ifndef SEX_H
#define SEX_H

#include <vector>
#include <string>

#include "action.h"
#include "game.h"   /** TODO Avoid this */

class Sex : public Action {
private:

public:
    Sex(EActions newtype, short time);

	void addActor(Caveman* actor);
	short resolve();
};

#endif