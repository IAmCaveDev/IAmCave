#ifndef COLLECT_H
#define COLLECT_H

#include <vector>
#include <string>
#include "action.h"

class Collect : public Action {
public:
	Collect(bool newIsEasy, short duration);

	void addActor(std::shared_ptr<Caveman> actor);
	ActionPackage resolve();
};

#endif
