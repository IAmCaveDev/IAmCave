#include "sex.h"

Sex::Sex(EActions newtype, short time) : Action(time){
    type = EActions::SexAction;
}

void Sex::addActor(Caveman* newactor) {
	actors.push_back(newactor);
}

short Sex::resolve() {
	short totalFitness = 0;
	unsigned int actors_involvedMale = 0;
	unsigned int actors_involvedFemale = 0;
	short luck = (short)std::rand() % 10;
	short successfulPregnancies;

	for (auto& it : actors) {
        totalFitness += it->getFitness();
		if (it->isMale())
			actors_involvedMale++;
		else
			actors_involvedFemale++;
		it->setCurrentAction(EActions::Idle);
	}

    totalFitness /= actors_involvedMale + actors_involvedFemale;
    /** Temprorary pregnancy formula */
	successfulPregnancies = (short)((totalFitness + luck) / (actors_involvedMale + actors_involvedFemale)) - 1;
	for (auto& it : actors) {
		if (!successfulPregnancies)
			break;
		if (!it->isMale()) {
			it->setPregnancy(true);
			successfulPregnancies--;
		}
	}
}