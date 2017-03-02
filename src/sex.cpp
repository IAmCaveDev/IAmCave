#include "sex.h"

Sex::Sex(short time, Game& gameRef) : Action(time, gameRef){
	//TODO
}

void Sex::addActor(Caveman* newactor) {
	actors.push_back(newactor);
}

void Sex::resolve() {

	short totalFitness = 0;
	unsigned int actors_involvedMale = 0;
	unsigned int actors_involvedFemale = 0;
	short luck = (short)std::rand() % 10;
	short successfullyPregnant;	//Amount of people getting pregnant this turn

	for (auto& it : actors) {

		totalFitness += it->getFitness;

		if (it->isMale())
			actors_involvedMale++;
		else
			actors_involvedFemale++;

		it->setCurrentAction(EActions::Idle);
	}

	//If only one gender present enter the Easter-Egg-Roulette
	if (!actors_involvedMale || !actors_involvedFemale) {

		//If max luck
		if (luck == 9)	{

			//Confirm crit
			if (std::rand() % 10)
				actors.at(std::rand() % actors.size)->setPregnancy(true);

		}
		return;
	}

	totalFitness /= actors_involvedMale + actors_involvedFemale;	//Get mean value

	//Temporary pregnancy formula
	successfullyPregnant = (short)((totalFitness + luck) / (actors_involvedMale + actors_involvedFemale)) - 1;

	for (auto& it : actors) {

		if (!successfullyPregnant)
			break;

		if (!it->isMale()) {
			it->setPregnancy(true);
			successfullyPregnant--;
		}
	}

}