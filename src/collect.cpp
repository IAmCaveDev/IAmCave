#include "collect.h"

Collect::Collect(short time) : Action(time) {
		type = EActions::Collect;
}

void Collect::addActor(std::shared_ptr<Caveman> newactor) {
	if(!newactor->isMale())
		actors.push_back(newactor);
}

ActionPackage Collect::resolve() {
	currentDuration += 1;

	if (currentDuration == totalDuration) {
		short totalFitness = 0;

		for (auto& it : actors) {
			totalFitness += it->getFitness();
			it->setCurrentAction(Idle);
		}
		// TODO Add gathering modifier
		int materials = totalFitness * totalDuration;

		return{ true, 0.f, materials, 0, false };
	}
}