#ifndef PREDATOR_H
#define PREDATOR_H

#include "animal.h"
#include "behaviour.h"

class SimManager;

class Predator: public Animal
{
public:
    Predator(SimManager* mgr, Cell* _cell);
    Predator(SimManager* mgr, Cell* cell, i16 satiety);
    void GetBehaviours() override;
    void Clone(Cell* cell) override;
    void Render() override;
};

#endif // PREDATOR_H
