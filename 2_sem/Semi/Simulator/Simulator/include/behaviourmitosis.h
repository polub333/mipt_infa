#ifndef BEHAVIOURMITOSIS_H
#define BEHAVIOURMITOSIS_H

#include "behaviour.h"

class BehaviourMitosis: public Behaviour
{
public:
    using Behaviour::Behaviour;
    virtual BehaviourApplicationResult Apply() override;
};

#endif // BEHAVIOURMITOSIS_H
