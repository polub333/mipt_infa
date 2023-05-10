#ifndef BEHAVIOURSTARVATION_H
#define BEHAVIOURSTARVATION_H

#include "behaviour.h"

class BehaviourStarvation: public Behaviour
{
public:
    using Behaviour::Behaviour;
    virtual BehaviourApplicationResult Apply() override;
};

#endif // BEHAVIOURSTARVATION_H
