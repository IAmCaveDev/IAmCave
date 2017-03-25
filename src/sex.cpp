#include "sex.h"

Sex::Sex(short time) : Action(time) {
	type = EActions::Collect;
}

void Sex::addActor(std::shared_ptr<Caveman> newactor) {
	if (actors.empty())
		actors.push_back(newactor);
	else if (actors.size() < 2 && actors.front()->isMale() != newactor->isMale())
		actors.push_back(newactor);
}

ActionPackage Sex::resolve() {
	currentDuration += 1;

	return{ true, 0, 0, 0, true };
}