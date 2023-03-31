#ifndef HERBIVOROUS_H
#define HERBIVOROUS_H

#include "animal.h"
#include "strategy.h"

class Herbivorous: public Animal
{
public:
    void Tick() override;
    Strategy* GetStrategies();
    Animal* Clone() override;
};

#endif // HERBIVOROUS_H
