#ifndef SEX_H
#define SEX_H

#include <vector>
#include <string>
#include "action.h"
#include "female.h"

class Sex : public Action {
public:
	Sex();

	void addActor(std::shared_ptr<Caveman> actor);
	ActionPackage resolve();
};

#endif
