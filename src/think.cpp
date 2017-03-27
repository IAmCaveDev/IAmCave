#include "think.h"

Think::Think(ETechs newtech, short time) : Action(time) {
	type = EActions::ThinkAction;
	tech = newtech;
}

void Think::addActor(std::shared_ptr<Caveman> newactor) {
	if (actors.size() < 1)
		actors.push_back(newactor);
}

ActionPackage Think::resolve() {
	currentDuration += 1;

	if (currentDuration == totalDuration) {
		actors.front()->setCurrentAction(Idle);
		return{ true, 0.f, 0, false };
	}

	return{ false, 0.f, 0, false };
}

//ETechs Think::getTech() {
//	return tech;
//}