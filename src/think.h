#ifndef SEX_H
#define SEX_H

#include <vector>
#include <string>

#include "action.h"

class Think : public Action {
private:

public:
    Think(EActions newtype, short time);

    void addActor(Caveman* actor);
    void resolve();
};

#endif