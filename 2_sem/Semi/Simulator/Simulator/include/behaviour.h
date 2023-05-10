#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include "animal.h"

enum BehaviourApplicationResult{
    R_CONTINUE,
    R_FINISH
};

class Behaviour
{
public:
    virtual BehaviourApplicationResult Apply() = 0;
    Behaviour(Animal* _animal);
protected:
    Animal* animal;
};

#endif // BEHAVIOUR_H
