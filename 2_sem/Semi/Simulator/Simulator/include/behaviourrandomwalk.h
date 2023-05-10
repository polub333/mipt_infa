#ifndef BEHAVIOURRANDOMWALK_H
#define BEHAVIOURRANDOMWALK_H

#include "behaviour.h"

class BehaviourRandomWalk: public Behaviour
{
public:
    using Behaviour::Behaviour;
    virtual BehaviourApplicationResult Apply() override;
};

#endif // BEHAVIOURRANDOMWALK_H
