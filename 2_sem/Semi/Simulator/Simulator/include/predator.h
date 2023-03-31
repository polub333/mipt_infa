#ifndef PREDATOR_H
#define PREDATOR_H

#include "animal.h"
#include "strategy.h"

class Predator: public Animal
{
public:
    void Tick() override;
    Strategy* GetStrategies();
    Animal* Clone() override;
};

#endif // PREDATOR_H
