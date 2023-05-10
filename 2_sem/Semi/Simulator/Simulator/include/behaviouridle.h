#ifndef BEHAVIOURIDLE_H
#define BEHAVIOURIDLE_H

#include "behaviour.h"

class BehaviourIdle: public Behaviour
{
public:
    using Behaviour::Behaviour;
    virtual BehaviourApplicationResult Apply() override;
};

#endif // BEHAVIOURIDLE_H
