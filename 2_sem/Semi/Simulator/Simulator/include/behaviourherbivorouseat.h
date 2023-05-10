#ifndef BEHAVIOURHERBIVOROUSEAT_H
#define BEHAVIOURHERBIVOROUSEAT_H

#include "behaviour.h"

class BehaviourHerbivorousEat: public Behaviour
{
public:
    using Behaviour::Behaviour;
    virtual BehaviourApplicationResult Apply() override;
};

#endif // BEHAVIOURHERBIVOROUSEAT_H
