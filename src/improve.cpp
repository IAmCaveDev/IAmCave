#include "improve.h"

Improve::Improve(short time) : Action(time) {
	type = EActions::ImproveAction;
}

void Improve::addActor(std::shared_ptr<Caveman> newactor) {
		actors.push_back(newactor);
}

ActionPackage Improve::resolve() {
    int materialCosts = actors.size() * 10;
	currentDuration += actors.size();

	if (currentDuration >= totalDuration) {
		for (auto& it : actors) {
			it->setCurrentAction(Idle);
		}
		return{ true, 0.f, 0, 1, false };
	}

	return{ false, 0.f, materialCosts, 0, false };
}