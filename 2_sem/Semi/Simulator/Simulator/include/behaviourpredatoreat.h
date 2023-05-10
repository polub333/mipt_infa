#ifndef BEHAVIOURPREDATOREAT_H
#define BEHAVIOURPREDATOREAT_H

#include "behaviour.h"

class BehaviourPredatorEat: public Behaviour
{
public:
    using Behaviour::Behaviour;
    virtual BehaviourApplicationResult Apply() override;
};

#endif // BEHAVIOURPREDATOREAT_H
