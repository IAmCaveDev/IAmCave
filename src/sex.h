#ifndef SEX_H
#define SEX_H

#include <vector>
#include <string>

#include "action.h"

class Sex : public Action {
private:

public:
    Sex(EActions newtype, short time);

	void addActor(Caveman* actor);
	void resolve();
};

#endif